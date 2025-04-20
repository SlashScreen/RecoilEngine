/* This file is part of the Recoil engine (GPL v2 or later), see LICENSE.html */

#pragma once

#include <vector>
#include <cstdint>

#include "3DModel.h"
#include "IModelParser.h"

namespace fastgltf {
	class Asset;
}

class GLTFPiece : public S3DModelPiece {
public:
	size_t nodeIndex = size_t(-1);
};

class CGLTFParser: public IModelParser
{
public:
	void Init() override {};
	void Kill() override {};

	void Load(S3DModel& model, const std::string& name) override;
private:
	GLTFPiece* AllocPiece();
	GLTFPiece* LoadPiece(S3DModel* model, GLTFPiece* parentPiece, const fastgltf::Asset& asset, size_t nodeIndex);

	std::vector<GLTFPiece> piecePool;
	spring::mutex poolMutex;

	uint32_t numPoolPieces = 0;
};
