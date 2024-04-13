#include "PZ_Shader.h"

Shader::Shader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	m_RendererID = glCreateProgram();
	m_VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	m_FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	std::string temp = LoadFile(vertexShaderPath);
	const char *tempc = temp.c_str();
	glShaderSource(m_VertexShaderID, 1, &tempc, 0);

	temp = LoadFile(fragmentShaderPath);
	tempc = temp.c_str();
	glShaderSource(m_VertexShaderID, 1, &tempc, 0);

	glCompileShader(m_VertexShaderID);
	glCompileShader(m_FragmentShaderID);

	glAttachShader(m_RendererID, m_VertexShaderID);
	glAttachShader(m_RendererID, m_FragmentShaderID);

	glLinkProgram(m_RendererID);
	glValidateProgram(m_RendererID);

	int result;
	glGetShaderiv(m_VertexShaderID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(m_VertexShaderID, GL_INFO_LOG_LENGTH, &length);
		char *message = (char*) _malloca(length);
		glGetShaderInfoLog(m_VertexShaderID, length, &length, message);
		std::cout << "Vertex shader error: " << message << "\n";
		exit(-1);
	}

	glGetShaderiv(m_FragmentShaderID, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(m_FragmentShaderID, GL_INFO_LOG_LENGTH, &length);
		char *message = (char*) _malloca(length);
		glGetShaderInfoLog(m_FragmentShaderID, length, &length, message);
		std::cout << "Fragment shader error: " << message << "\n";
		exit(-1);
	}

	glUseProgram(m_RendererID);
}

Shader::~Shader()
{
	glDeleteShader(m_VertexShaderID);
	glDeleteShader(m_FragmentShaderID);
	glDeleteProgram(m_RendererID);
}

void Shader::SetUniform1i(const std::string& name, int value)
{
	glUniform1i(GetUniformLocation(name), value);
}

void Shader::SetUniformMat4(const std::string& name, const glm::mat4x4& matrix)
{
	glUniformMatrix4fv(GetUniformLocation(name), 1, false, glm::value_ptr(matrix));
}

std::string Shader::LoadFile(const std::string& filepath)
{
	std::fstream file(filepath.c_str());
	if (!file.good())
	{
		std::cout << "Failed to read file '" + filepath + "'.\n";
		exit(0);
	}
	return std::string(
		std::istreambuf_iterator<char>(file),
		std::istreambuf_iterator<char>()
	);
}

inline int Shader::GetUniformLocation(const std::string& filepath)
{
	int location = glGetUniformLocation(m_RendererID, filepath.c_str());
	if (!location)
	{
		std::cout << "Failed to locate uniform '" << filepath << "'.\n";
		exit(-1);
	}
	return location;
}

void Shader::Bind() const
{
	glUseProgram(m_RendererID);
}

void Shader::Unbind() const
{
	glUseProgram(0);
}