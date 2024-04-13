#pragma once

#include <glad/gl.h>
#include <stdint.h>
#include <vector>

class VertexBuffer
{
	uint32_t m_BufferID = 0;
public:
	VertexBuffer(std::vector<float> data, size_t size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};

class IndexBuffer
{
	uint32_t m_BufferID = 0;
	size_t m_Count = 0;
public:
	IndexBuffer(std::vector<uint32_t> data, size_t size, size_t count);
	~IndexBuffer();

	inline size_t GetCount() { return m_Count; }

	void Bind() const;
	void Unbind() const;
};