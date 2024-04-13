#include "PZ_Buffer.h"

VertexBuffer::VertexBuffer(std::vector<float> data, size_t size)
	: m_BufferID(0)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(float), data.data(), GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_BufferID);
}

void VertexBuffer::Unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

IndexBuffer::IndexBuffer(std::vector<uint32_t> data, size_t size, size_t count)
	: m_BufferID(0), m_Count(count)
{
	glGenBuffers(1, &m_BufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(uint32_t), data.data(), GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BufferID);
}

void IndexBuffer::Unbind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}