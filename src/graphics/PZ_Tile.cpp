#include "PZ_Tile.h"

Tile::~Tile()
{
}

void Tile::Create(const TileTypes& type)
{
	std::vector<float> vertices = 
	{
		1280.0f, 720.0f, 0.0f, 0.0f, 1.0f,
		1190.0f, 720.0f, 0.0f, 1.0f, 1.0f,
		1280.0f, 660.0f, 0.0f, 0.0f, 0.0f,
		1190.0f, 660.0f, 0.0f, 1.0f, 0.0f
	};

	std::vector<uint32_t> indices = 
	{
		0, 1, 2,
		2, 3, 0
	};

	m_VertexBuffer = std::make_shared<VertexBuffer>(vertices, vertices.size());
	m_VertexArray.Push<float>(std::make_tuple(0, 3, 0));
	m_VertexArray.Push<float>(std::make_tuple(1, 2, 3));
	m_IndexBuffer = std::make_shared<IndexBuffer>(indices, indices.size(), indices.size() / 2);
	m_Shader = std::make_shared<Shader>("PZ_SHADERS/tile.vert", "PZ_SHADERS/tile.frag");
	m_Shader->SetUniform1i("u_tex2D", 0.0f);
	m_Shader->SetUniformMat4("u_proj", glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f, -1.0f, 1.0f));
	switch (type)
	{
		case TileTypes::Sunflower:
			m_Texture = std::make_shared<Texture>("PZ_TEXTURES/sunflower.png");
			break;
	}
	m_Texture->Bind(0);
}

void Tile::Update()
{
}

void Tile::Render(const glm::vec3& pos)
{
	Renderer::DrawTile(m_VertexArray, *m_IndexBuffer.get(), *m_Shader.get(), *m_Texture.get(),
		0, glm::translate(glm::mat4(1.0f), pos));
}