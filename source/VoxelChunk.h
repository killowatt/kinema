#pragma once

#include <atomic>
#include <vector>

#include "glm/vec3.hpp"

#include "Renderer/Device.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/DebugRenderer.h"
#include "Voxel.h"

#include "PxPhysicsAPI.h"
using namespace physx;

class VoxelChunk
{
public:
	bool ready = false;
	bool needsupdate = false;

	std::vector<Block> Blocks;

	std::vector<uint32_t> vertices;
	std::vector<float> verticesCollision;
	std::vector<uint32_t> indices;

	glm::ivec3 Dimensions;
	glm::ivec3 loc;

	VertexBuffer* VB;
	IndexBuffer* IB;

	class VoxelMesh* ParentMesh;

	uint32_t temp_indices_count = 0;

	VoxelChunk();
	~VoxelChunk();

	Block GetBlockLocal(int32_t x, int32_t y, int32_t z);
	Block GetBlockLocal(glm::ivec3 coord);

	void Update();
	void Update_Upload();

	void cleardata();

	void DrawChunkBoundary(Device* device, DebugRenderer* db, glm::mat4 t);

private:
	inline BlockFace GetBlockFace(const glm::ivec3& inCoordinate, uint8_t side);
};