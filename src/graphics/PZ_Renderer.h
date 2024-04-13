#pragma once

#include <glad/gl.h>
#include "PZ_VertexArray.h"
#include "PZ_Buffer.h"
#include "PZ_Shader.h"
#include "PZ_Texture.h"

#include <glm/glm.hpp>

enum class RendererTypes
{
	OpenGL = 0,
	OpenGL_M2 = 2,
	OpenGL_M3 = 3
};

enum class TileTypes
{
	Sunflower = 0
};

class Renderer
{
public:
	Renderer(const Renderer&) = delete;

	static void DrawTile(VertexArray& vertexarray, IndexBuffer& indexbuffer, Shader& shader,
		Texture& texture, uint32_t slot = 0, const glm::mat4x4& model = glm::mat4x4(1.0f)) 
	{
		texture.Bind(slot);
		shader.Bind();
		shader.SetUniformMat4("u_model", model);
		vertexarray.Bind();
		indexbuffer.Bind();
		glDrawElements(GL_TRIANGLES, indexbuffer.GetCount(), GL_UNSIGNED_INT, (const void*)0);
		indexbuffer.Unbind();
		vertexarray.Unbind();
		shader.Unbind();
		texture.Unbind();
	}
};