#pragma once

#include "PZ_Buffer.h"
#include "PZ_Shader.h"
#include "PZ_Texture.h"
#include "PZ_Renderer.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <memory>
#include <tuple>

class Tile
{
	VertexArray m_VertexArray;
	std::shared_ptr<VertexBuffer> m_VertexBuffer;
	std::shared_ptr<IndexBuffer> m_IndexBuffer;
	std::shared_ptr<Shader> m_Shader;
	std::shared_ptr<Texture> m_Texture;

	glm::vec3 m_TilePos;
public:
	Tile() = default;
	~Tile();

	void Create(const TileTypes& type);
	void Update();
	void Render(const glm::vec3& pos = { 0, 0, 0 });
};