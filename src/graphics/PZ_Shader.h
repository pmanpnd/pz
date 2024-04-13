#pragma once

#include <glad/gl.h>
#include <stdint.h>
#include <string>
#include <fstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
	uint32_t m_RendererID, m_VertexShaderID, m_FragmentShaderID;
private:
	std::string LoadFile(const std::string& filepath);
	inline int GetUniformLocation(const std::string& filepath);
public:
	Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	~Shader();

	void SetUniform1i(const std::string& name, int value);
	void SetUniformMat4(const std::string& name, const glm::mat4x4& matrix);

	void Bind() const;
	void Unbind() const;
};