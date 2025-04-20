#pragma once

#include <vector>


#include "3DModel.h"

namespace Skinning {
	struct SkinnedMesh {
		std::vector<SVertexData> verts;
		std::vector<uint32_t> indcs;
	};

	static std::vector<size_t> boneWeights;

	uint16_t GetBoneID(const SVertexData& vert, size_t wi);

	void ReparentMeshesTrianglesToBones(S3DModel* model, const std::vector<SkinnedMesh>& meshes);
	void ReparentCompleteMeshesToBones (S3DModel* model, const std::vector<SkinnedMesh>& meshes);
};