#pragma once

#include <glad/gl.h>
#include <stdint.h>
#include <vector>
#include <tuple>

class VertexBufferLayout
{
	std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> m_Layout;
public:
	VertexBufferLayout(const std::tuple<uint32_t, uint32_t, uint32_t, uint32_t>& layout) : m_Layout(layout) {};
	inline std::tuple<uint32_t, uint32_t, uint32_t, uint32_t> GetLayout() { return m_Layout; }
};

class VertexArray
{
	std::vector<VertexBufferLayout> m_Layouts;
	uint32_t m_RendererID, m_Stride;
private:
	size_t GetTypeSizeFromTag(uint32_t type)
	{
		switch (type)
		{
			case GL_FLOAT:
				return sizeof(float);
		}
		return 0;
	}
public:
	VertexArray();
	~VertexArray();

	// Index, count & offset are the parameters.
	template <class T>
	void Push(const std::tuple<uint32_t, uint32_t, uint32_t>& layout);
	// Index, count & offset are the parameters.
	template <>
	void Push<float>(const std::tuple<uint32_t, uint32_t, uint32_t>& layout);

	void ApplyAttribs();

	void Bind() const;
	void Unbind() const;
};