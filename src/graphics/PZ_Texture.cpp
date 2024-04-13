#include "PZ_Texture.h"

Texture::Texture(const std::string& filepath)
	: m_RendererID(0)
{
	stbi_set_flip_vertically_on_load(true);
	m_ImgData = stbi_load(filepath.c_str(), &m_ImgWidth, &m_ImgHeight, &m_BPP, 4);
	
	glGenTextures(1, &m_RendererID);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA2, m_ImgWidth, m_ImgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_ImgData);
	glBindTexture(GL_TEXTURE_2D, 0);
	delete[] m_ImgData;
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_RendererID);
}

void Texture::Bind(uint32_t slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_RendererID);
}

void Texture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}