/* This file is part of the Recoil engine (GPL v2 or later), see LICENSE.html */

#include <vector>
#include <numeric>
#include <algorithm>

#include "GLTFParser.h"
#include "3DModel.h"
#include "3DModelLog.h"
#include "SkinningUtils.h"

#include "Rendering/Textures/S3OTextureHandler.h"
#include "System/FileSystem/FileHandler.h"
#include "System/FileSystem/FileSystem.h"
#include "System/Misc/TracyDefs.h"
#include "System/Exceptions.h"
#include "System/UnorderedSet.hpp"

#include <fastgltf/core.hpp>
#include <fastgltf/tools.hpp>
#include <fastgltf/math.hpp>


namespace Impl {
	Transform TRStoTransform(const fastgltf::TRS& trs) {
		assert(float3(trs.scale.x(), trs.scale.y(), trs.scale.z()) == float3(trs.scale.x()));
		return Transform{
			CQuaternion{ trs.rotation.x(), trs.rotation.y(), trs.rotation.z(), trs.rotation.w()},
			float3{ trs.translation.x(), trs.translation.y(), trs.translation.z() },
			trs.scale.x()
		};
	}
	Transform MatrixToTransform(const fastgltf::math::fmat4x4& matrix) {
		CMatrix44f mat;
		memcpy(&mat.m[0], matrix.data(), sizeof(CMatrix44f));
		auto [t, r, s] = mat.DecomposeIntoTRS();
		assert(s == float3(s));
		return Transform{ r, t, s.x };
	}

	template<typename PrimContainer>
	void ReadGeometryData(const fastgltf::Asset& asset, const PrimContainer& primitives, std::vector<SVertexData>& verts, std::vector<uint32_t>& indcs) {
			for (const auto& prim : primitives) {
			const size_t prevVertSize = verts.size();
			const size_t prevIndcSize = indcs.size();

			std::vector<std::vector<std::pair<uint16_t, float>>> vertexWeights;

			assert(prim.type == fastgltf::PrimitiveType::Triangles);
			for (const auto* primAttIt = prim.attributes.cbegin(); primAttIt != prim.attributes.cend(); ++primAttIt) {
				auto& accessor = asset.accessors[primAttIt->accessorIndex];

				if (primAttIt == prim.attributes.cbegin()) {
					verts.resize(prevVertSize + accessor.count);
					vertexWeights.resize(accessor.count, std::vector<std::pair<uint16_t, float>>(8, std::make_pair(SVertexData::INVALID_BONEID, 0.0f)));
				}

				if (!accessor.bufferViewIndex.has_value())
					continue;

				switch (hashString(primAttIt->name.c_str(), primAttIt->name.length()))
				{
				case hashString("POSITION"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec3>(asset, accessor, [&](const auto& val, std::size_t idx) {
						verts[prevVertSize + idx].pos = float3{ val.x(), val.y(), val.z() };
					});
				} break;
				case hashString("NORMAL"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec3>(asset, accessor, [&](const auto& val, std::size_t idx) {
						verts[prevVertSize + idx].normal = float3{ val.x(), val.y(), val.z() }.ANormalize();
					});
				} break;
				case hashString("TEXCOORD_0"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec2>(asset, accessor, [&](const auto& val, std::size_t idx) {
						verts[prevVertSize + idx].texCoords[0] = float2(val.x(), val.y());
					});
				} break;
				case hashString("TEXCOORD_1"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec2>(asset, accessor, [&](const auto& val, std::size_t idx) {
						verts[prevVertSize + idx].texCoords[1] = float2(val.x(), val.y());
					});
				} break;
				case hashString("TANGENT"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec4>(asset, accessor, [&](const auto& val, std::size_t idx) {
						verts[prevVertSize + idx].sTangent = (val.w() * float3{ val.x(), val.y(), val.z() }).ANormalize();
						verts[prevVertSize + idx].tTangent = verts[prevVertSize + idx].normal.cross(verts[prevVertSize + idx].sTangent).ANormalize();
					});
				} break;
				case hashString("JOINTS_0"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::uvec4>(asset, accessor, [&](const auto& val, std::size_t idx) {
						auto& vertexWeight = vertexWeights[idx];
						vertexWeight[0].first = static_cast<uint16_t>(val.x());
						vertexWeight[1].first = static_cast<uint16_t>(val.y());
						vertexWeight[2].first = static_cast<uint16_t>(val.z());
						vertexWeight[3].first = static_cast<uint16_t>(val.w());
					});
				} break;
				case hashString("JOINTS_1"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::uvec4>(asset, accessor, [&](const auto& val, std::size_t idx) {
						auto& vertexWeight = vertexWeights[idx];
						vertexWeight[4].first = static_cast<uint16_t>(val.x());
						vertexWeight[5].first = static_cast<uint16_t>(val.y());
						vertexWeight[6].first = static_cast<uint16_t>(val.z());
						vertexWeight[7].first = static_cast<uint16_t>(val.w());
					});
				} break;
				case hashString("WEIGHTS_0"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec4>(asset, accessor, [&](const auto& val, std::size_t idx) {
						auto& vertexWeight = vertexWeights[idx];
						vertexWeight[0].second = val.x();
						vertexWeight[1].second = val.y();
						vertexWeight[2].second = val.z();
						vertexWeight[3].second = val.w();
					});
				} break;
				case hashString("WEIGHTS_1"): {
					fastgltf::iterateAccessorWithIndex<fastgltf::math::fvec4>(asset, accessor, [&](const auto& val, std::size_t idx) {
						auto& vertexWeight = vertexWeights[idx];
						vertexWeight[4].second = val.x();
						vertexWeight[5].second = val.y();
						vertexWeight[6].second = val.z();
						vertexWeight[7].second = val.w();
					});
				} break;
				default:
					break;
				}
			}

			for (auto& vertexWeight : vertexWeights) {
				for (auto& w : vertexWeight) {
					if (w.second == 0.0f)
						w.first = SVertexData::INVALID_BONEID;
				}
				std::stable_sort(vertexWeight.begin(), vertexWeight.end(), [](const auto& lhs, const auto& rhs) {
					return std::forward_as_tuple(lhs.second, lhs.first) > std::forward_as_tuple(rhs.second, rhs.first);
				});
				vertexWeight.resize(4, std::make_pair(255, 0.0f));
			}

			for (size_t i = prevVertSize; i < verts.size(); ++i) {
				verts[i].SetBones(vertexWeights[i - prevVertSize]);
			}

			assert(prim.indicesAccessor.has_value());
			auto& accessor = asset.accessors[*prim.indicesAccessor];
			indcs.resize(prevIndcSize + accessor.count);

			assert(accessor.bufferViewIndex.has_value());
			fastgltf::iterateAccessorWithIndex<uint32_t>(asset, accessor, [&](std::uint32_t index, std::size_t idx) {
				indcs[idx] = index;
			});
		}
	}
	void ReplaceNodeIndexWithPieceIndex(std::vector<SVertexData>& verts, const spring::unordered_map<size_t, size_t>& nodeIdxToPieceIdx) {
		for (auto& vert : verts) {
			for (size_t wi = 0; wi < vert.boneIDsLow.size(); ++wi) {
				const auto nodeIdx = Skinning::GetBoneID(vert, wi);
				if (nodeIdx == INV_PIECE_NUM)
					continue;

				const auto pIt = nodeIdxToPieceIdx.find(nodeIdx);
				assert(pIt != nodeIdxToPieceIdx.end());
				vert.boneIDsLow [wi] = static_cast<uint8_t>((pIt->second >> 0) & 0xFF);
				vert.boneIDsHigh[wi] = static_cast<uint8_t>((pIt->second >> 8) & 0xFF);
			}
		}
	}
}

void CGLTFParser::Load(S3DModel& model, const std::string& modelFilePath)
{
	RECOIL_DETAILED_TRACY_ZONE;
	LOG_SL(LOG_SECTION_MODEL, L_INFO, "Loading model: %s", modelFilePath.c_str());

	const std::string modelPath = FileSystem::GetDirectory(modelFilePath);
	const std::string modelName = FileSystem::GetBasename(modelFilePath);

	CFileHandler file(modelFilePath, SPRING_VFS_ZIP);
	std::vector<uint8_t> fileBuf;
	if (!file.IsBuffered()) {
		const auto fs = file.FileSize();
		if (fs <= 0)
			throw content_error("An assimp model has invalid size of " + std::to_string(fs));

		fileBuf.resize(fs, 0);
		file.Read(fileBuf.data(), fileBuf.size());
	}
	else {
		fileBuf = std::move(file.GetBuffer());
	}

	auto gltfFile = fastgltf::GltfDataBuffer::FromBytes(reinterpret_cast<std::byte*>(fileBuf.data()), fileBuf.size());
	if (gltfFile.error() != fastgltf::Error::None) {
		// The file couldn't be loaded, or the buffer could not be allocated.
		throw content_error("Error loading GLTF file " + modelFilePath);
	}

	fastgltf::Parser parser;

	static constexpr auto PARSER_OPTION =
		fastgltf::Options::DontRequireValidAssetMember | 
		//fastgltf::Options::DecomposeNodeMatrices | // most likely sync unsafe, however this doesn't mean the transformation type is always matrix
		fastgltf::Options::GenerateMeshIndices;

	static constexpr auto PARSER_CATEGORIES =
		fastgltf::Category::Buffers |
		fastgltf::Category::BufferViews |
		fastgltf::Category::Accessors |
		fastgltf::Category::Images | //?
		fastgltf::Category::Animations |
		fastgltf::Category::Meshes |
		fastgltf::Category::Skins |
		fastgltf::Category::Nodes |
		fastgltf::Category::Scenes |
		fastgltf::Category::Asset;

	auto maybeGltf = parser.loadGltf(gltfFile.get(), modelPath, PARSER_OPTION, PARSER_CATEGORIES);
	if (auto error = maybeGltf.error(); error != fastgltf::Error::None) {
		throw content_error("Error loading GLTF file " + modelFilePath);
	}

	const auto& asset = maybeGltf.get();

	if (asset.scenes.empty()) {
		throw content_error("Error loading GLTF file " + modelFilePath);
	}

	model.name = modelFilePath;
	model.type = MODELTYPE_ASS; // Revise?
	model.numPieces = 0;
	model.texs[0] = "";//(header.texture1 == 0) ? "" : (char*)&fileBuf[header.texture1];
	model.texs[1] = "";//(header.texture2 == 0) ? "" : (char*)&fileBuf[header.texture2];
	model.mins = DEF_MIN_SIZE;
	model.maxs = DEF_MAX_SIZE;

	//textureHandlerS3O.PreloadTexture(&model);
	//gltf.
	//std::vector<std::pair<SVertexData, uint32_t>> allMeshes
	/*

	*/




	//std::vector<std::pair<SVertexData, uint32_t>> allMeshes
	
	const auto defaultSceneIdx = asset.defaultScene.value_or(0);
	const auto& defaultScene = asset.scenes[defaultSceneIdx];
	auto* rootPiece = LoadPiece(&model, nullptr, asset, defaultScene.nodeIndices.front());
	rootPiece->SetPieceTransform(Transform{});
	model.FlattenPieceTree(rootPiece);

	spring::unordered_map<size_t, size_t> nodeIdxToPieceIdx;
	for (size_t pi = 0; pi < model.pieceObjects.size(); ++pi) {
		const auto* piece = static_cast<const GLTFPiece*>(model.pieceObjects[pi]);
		nodeIdxToPieceIdx[piece->nodeIndex] = pi;
	}

	std::vector<Skinning::SkinnedMesh> allSkinnedMeshes;

	for (size_t ni = 0; ni < asset.nodes.size(); ++ni) {
		const auto& node = asset.nodes[ni];
		if (!node.meshIndex.has_value())
			continue;

		if (!node.skinIndex.has_value())
			continue;

		const auto& mesh = asset.meshes[*node.meshIndex];
		auto& skinnedMesh = allSkinnedMeshes.emplace_back();
		Impl::ReadGeometryData(asset, mesh.primitives, skinnedMesh.verts, skinnedMesh.indcs);
		Impl::ReplaceNodeIndexWithPieceIndex(skinnedMesh.verts, nodeIdxToPieceIdx);
	}

	spring::unordered_set<size_t> allBones;
	for (const auto& skin : asset.skins) {
		for (size_t ji = 0; ji < skin.joints.size(); ++ji) {
			allBones.emplace(skin.joints[ji]);
		}
	}
	LOG("");

	// if numMeshes >= numBones reparent the whole meshes
	// else reparent meshes per-triangle
	if (allSkinnedMeshes.size() >= allBones.size())
		Skinning::ReparentCompleteMeshesToBones(&model, allSkinnedMeshes);
	else
		Skinning::ReparentMeshesTrianglesToBones(&model, allSkinnedMeshes);

	// set after the extrema are known
	//model.radius = (header.radius <= 0.01f) ? model.CalcDrawRadius() : header.radius;
	//model.height = (header.height <= 0.01f) ? model.CalcDrawHeight() : header.height;
	//model.relMidPos = float3(header.midx, header.midy, header.midz);

}

GLTFPiece* CGLTFParser::AllocPiece()
{
	RECOIL_DETAILED_TRACY_ZONE;
	std::lock_guard<spring::mutex> lock(poolMutex);

	// lazily reserve pool here instead of during Init
	// this way games using only one model-type do not
	// cause redundant allocation
	if (piecePool.empty())
		piecePool.resize(MAX_MODEL_OBJECTS * AVG_MODEL_PIECES);

	if (numPoolPieces >= piecePool.size()) {
		throw std::bad_alloc();
		return nullptr;
	}

	return &piecePool[numPoolPieces++];
}


GLTFPiece* CGLTFParser::LoadPiece(S3DModel* model, GLTFPiece* parentPiece, const fastgltf::Asset& asset, size_t nodeIndex)
{
	const auto& node = asset.nodes[nodeIndex];

	// skip skinned meshes (handled separately)
	if (node.skinIndex.has_value())
		return nullptr;

	auto* piece = AllocPiece();
	model->numPieces++;

	piece->SetParentModel(model);
	piece->parent = parentPiece;
	piece->name = node.name;
	piece->children.reserve(node.children.size());
	piece->nodeIndex = nodeIndex;

	Transform bakedTra = fastgltf::visit_exhaustive(fastgltf::visitor{
		[&](const fastgltf::math::fmat4x4& matrix) {
			return Impl::MatrixToTransform(matrix);
		},
		[&](const fastgltf::TRS& trs) {
			return Impl::TRStoTransform(trs);
		}
	}, node.transform);
	
	piece->SetBakedTransform(bakedTra);
	piece->offset = piece->bakedTransform.t;
	piece->goffset = piece->offset + ((parentPiece != nullptr) ? parentPiece->goffset : ZeroVector);


	for (const auto childNodeIndex : node.children) {
		auto* childPiece = LoadPiece(model, piece, asset, childNodeIndex);
		if (childPiece)
			piece->children.push_back(childPiece);
	}

	if (!node.meshIndex.has_value())
		return piece;

	auto& verts = piece->GetVerticesVec();
	auto& indcs = piece->GetIndicesVec();
	const auto& mesh = asset.meshes[*node.meshIndex];
	Impl::ReadGeometryData(asset, mesh.primitives, verts, indcs);

	return piece;
}
