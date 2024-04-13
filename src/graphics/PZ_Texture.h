#pragma once

#include <glad/gl.h>
#include <stb_image.h>

#include <string>
#include <stdint.h>

class Texture
{
	uint32_t m_RendererID;
	int m_ImgWidth, m_ImgHeight, m_BPP;
	uint8_t* m_ImgData;
public:
	Texture(const std::string& filepath);
	~Texture();

	void Bind(uint32_t slot = 0) const;
	void Unbind();
};