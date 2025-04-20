#include "SkinningUtils.h"

#include <cassert>
#include <numeric>

#include "System/Misc/TracyDefs.h"

using namespace Skinning;

uint16_t Skinning::GetBoneID(const SVertexData& vert, size_t wi)
{
	return vert.boneIDsLow[wi] | (vert.boneIDsHigh[wi] << 8);
};

void Skinning::ReparentMeshesTrianglesToBones(S3DModel* model, const std::vector<SkinnedMesh>& meshes)
{
	RECOIL_DETAILED_TRACY_ZONE;

	boneWeights.resize(INV_PIECE_NUM + 1);

	for (const auto& mesh : meshes) {
		const auto& verts = mesh.verts;
		const auto& indcs = mesh.indcs;

		for (size_t trID = 0; trID < indcs.size() / 3; ++trID) {

			std::fill(boneWeights.begin(), boneWeights.end(), 0);
			for (size_t vi = 0; vi < 3; ++vi) {
				const auto& vert = verts[indcs[trID * 3 + vi]];

				for (size_t wi = 0; wi < 4; ++wi) {
					boneWeights[GetBoneID(vert, wi)] += vert.boneWeights[wi];
				}
			}

			const auto maxWeightedBoneID = std::distance(
				boneWeights.begin(),
				std::max_element(boneWeights.begin(), boneWeights.end())
			);
			assert(maxWeightedBoneID < INV_PIECE_NUM); // INV_PIECE_NUM - invalid bone

			auto* maxWeightedPiece = model->pieceObjects[maxWeightedBoneID];

			auto& pieceVerts = maxWeightedPiece->GetVerticesVec();
			auto& pieceIndcs = maxWeightedPiece->GetIndicesVec();

			for (size_t vi = 0; vi < 3; ++vi) {
				auto  targVert = verts[indcs[trID * 3 + vi]]; //copy

				// find if targVert is already added
				auto itTargVec = std::find_if(pieceVerts.begin(), pieceVerts.end(), [&targVert](const auto& vert) {
					return targVert.pos.equals(vert.pos) && targVert.normal.equals(vert.normal);
				});

				// new vertex
				if (itTargVec == pieceVerts.end()) {
					// make sure maxWeightedBoneID comes first. It's a must, even if it doesn't exist in targVert.boneIDs!
					const auto boneID0 = GetBoneID(targVert, 0);
					if (boneID0 != maxWeightedBoneID) {
						size_t itPos = 0;
						for (size_t jj = 1; jj < targVert.boneIDsLow.size(); ++jj) {
							if (GetBoneID(targVert, jj) == maxWeightedBoneID) {
								itPos = jj;
								break;
							}
						}
						if (itPos != 0) {
							// swap maxWeightedBoneID so it comes first in the boneIDs array
							std::swap(targVert.boneIDsLow[0], targVert.boneIDsLow[itPos]);
							std::swap(targVert.boneWeights[0], targVert.boneWeights[itPos]);
							std::swap(targVert.boneIDsHigh[0], targVert.boneIDsHigh[itPos]);
						}
						else {
							// maxWeightedBoneID doesn't even exist in this targVert
							// replace the bone with the least weight with maxWeightedBoneID and swap it be first
							targVert.boneIDsLow[3]  = static_cast<uint8_t>((maxWeightedBoneID     ) & 0xFF);
							targVert.boneWeights[3] = 0;
							targVert.boneIDsHigh[3] = static_cast<uint8_t>((maxWeightedBoneID >> 8) & 0xFF);
							std::swap(targVert.boneIDsLow[0], targVert.boneIDsLow[3]);
							std::swap(targVert.boneWeights[0], targVert.boneWeights[3]);
							std::swap(targVert.boneIDsHigh[0], targVert.boneIDsHigh[3]);

							// renormalize weights (optional but nice for debugging)
							const float sumWeights = static_cast<float>(std::reduce(targVert.boneWeights.begin(), targVert.boneWeights.end())) / 255.0;
							for (auto& bw : targVert.boneWeights) {
								bw = static_cast<uint8_t>(math::round(static_cast<float>(bw) / 255.0f / sumWeights));
							}
						}
					}

					pieceIndcs.emplace_back(static_cast<uint32_t>(pieceVerts.size()));
					pieceVerts.emplace_back(std::move(targVert));
				}
				else {
					pieceIndcs.emplace_back(static_cast<uint32_t>(std::distance(
						pieceVerts.begin(),
						itTargVec
					)));
				}
			}
		}
	}

	// transform model space mesh vertices into bone/piece space
	for (auto* piece : model->pieceObjects) {
		if (!piece->HasGeometryData())
			continue;

		const auto invTra = piece->bposeTransform.InvertAffine();
		for (auto& vert : piece->GetVerticesVec()) {
			vert.pos      = (invTra * float4{ vert.pos     , 1.0f }).xyz;
			vert.normal   = (invTra * float4{ vert.normal  , 0.0f }).xyz;
			vert.sTangent = (invTra * float4{ vert.sTangent, 0.0f }).xyz;
			vert.tTangent = (invTra * float4{ vert.tTangent, 0.0f }).xyz;
		}
	}
}

void Skinning::ReparentCompleteMeshesToBones(S3DModel* model, const std::vector<SkinnedMesh>& meshes) {
	RECOIL_DETAILED_TRACY_ZONE;

	boneWeights.resize(INV_PIECE_NUM + 1);

	for (const auto& mesh : meshes) {
		const auto& verts = mesh.verts;
		const auto& indcs = mesh.indcs;

		std::fill(boneWeights.begin(), boneWeights.end(), 0);
		for (const auto& vert : verts) {
			for (size_t wi = 0; wi < 4; ++wi) {
				boneWeights[GetBoneID(vert, wi)] += vert.boneWeights[wi];
			}
		}
		const auto maxWeightedBoneID = std::distance(
			boneWeights.begin(),
			std::max_element(boneWeights.begin(), boneWeights.end())
		);
		assert(maxWeightedBoneID < INV_PIECE_NUM); // INV_PIECE_NUM - invalid bone

		auto* maxWeightedPiece = model->pieceObjects[maxWeightedBoneID];

		auto& pieceVerts = maxWeightedPiece->GetVerticesVec();
		auto& pieceIndcs = maxWeightedPiece->GetIndicesVec();
		const auto indexOffset = static_cast<uint32_t>(pieceVerts.size());

		for (auto targVert : verts) { // deliberate copy
			// Unlike ReparentMeshesTrianglesToBones() do not check for already existing vertices
			// Just copy mesh as is. Modelers and assimp should have done necessary dedup for us.

			// make sure maxWeightedBoneID comes first. It's a must, even if it doesn't exist in targVert.boneIDs!
			const auto boneID0 = GetBoneID(targVert, 0);
			if (boneID0 != maxWeightedBoneID) {
				size_t itPos = 0;
				for (size_t jj = 1; jj < targVert.boneIDsLow.size(); ++jj) {
					if (GetBoneID(targVert, jj) == maxWeightedBoneID) {
						itPos = jj;
						break;
					}
				}
				if (itPos != 0) {
					// swap maxWeightedBoneID so it comes first in the boneIDs array
					std::swap(targVert.boneIDsLow[0], targVert.boneIDsLow[itPos]);
					std::swap(targVert.boneWeights[0], targVert.boneWeights[itPos]);
					std::swap(targVert.boneIDsHigh[0], targVert.boneIDsHigh[itPos]);
				}
				else {
					// maxWeightedBoneID doesn't even exist in this targVert
					// replace the bone with the least weight with maxWeightedBoneID and swap it be first
					targVert.boneIDsLow[3] = static_cast<uint8_t>((maxWeightedBoneID) & 0xFF);
					targVert.boneWeights[3] = 0;
					targVert.boneIDsHigh[3] = static_cast<uint8_t>((maxWeightedBoneID >> 8) & 0xFF);
					std::swap(targVert.boneIDsLow[0], targVert.boneIDsLow[3]);
					std::swap(targVert.boneWeights[0], targVert.boneWeights[3]);
					std::swap(targVert.boneIDsHigh[0], targVert.boneIDsHigh[3]);

					// renormalize weights (optional but nice for debugging)
					const float sumWeights = static_cast<float>(std::reduce(targVert.boneWeights.begin(), targVert.boneWeights.end())) / 255.0;
					for (auto& bw : targVert.boneWeights) {
						bw = static_cast<uint8_t>(math::round(static_cast<float>(bw) / 255.0f / sumWeights));
					}
				}
			}

			pieceVerts.emplace_back(std::move(targVert));
		}

		for (const auto indx : indcs) {
			pieceIndcs.emplace_back(indexOffset + indx);
		}
	}

	// transform model space mesh vertices into bone/piece space
	for (auto* piece : model->pieceObjects) {
		if (!piece->HasGeometryData())
			continue;

		const auto invTra = piece->bposeTransform.InvertAffine();
		for (auto& vert : piece->GetVerticesVec()) {
			vert.pos      = (invTra * float4{ vert.pos     , 1.0f }).xyz;
			vert.normal   = (invTra * float4{ vert.normal  , 0.0f }).xyz;
			vert.sTangent = (invTra * float4{ vert.sTangent, 0.0f }).xyz;
			vert.tTangent = (invTra * float4{ vert.tTangent, 0.0f }).xyz;
		}
	}
}
