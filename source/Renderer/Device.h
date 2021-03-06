#pragma once

#include <cstdint>
#include <string>

#include "SDL2/SDL.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"

class Device
{
public:
	Device(SDL_Window* window);
	~Device();

	void Clear();

	void SetShader(Shader* shader);

	void Draw(VertexBuffer* vertexBuffer, uint32_t count);
	void Draw(VertexBuffer* vertexBuffer, IndexBuffer* indexBuffer, uint32_t count);
	void DrawLines(VertexBuffer* vertexBuffer, uint32_t count);

	void CheckErrorTemp();

	std::string GetAPIVersion();
	std::string GetDeviceName();
	std::string GetDeviceVendor();

public:
	SDL_GLContext Context;

	uint32_t VertexArrayObject;
	size_t CurrentAttributeCount;

	void SetupVertexAttributes(const std::vector<VertexAttribute>& attributes);
};