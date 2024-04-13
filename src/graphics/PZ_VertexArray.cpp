#include "PZ_VertexArray.h"

VertexArray::VertexArray()
	: m_RendererID(0), m_Stride(0)
{
	m_Layouts.reserve(2);
	glGenVertexArrays(1, &m_RendererID);
	glBindVertexArray(m_RendererID);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_RendererID);
}

template<class T>
void VertexArray::Push(const std::tuple<uint32_t, uint32_t, uint32_t>& layout)
{
}

template <>
void VertexArray::Push<float>(const std::tuple<uint32_t, uint32_t, uint32_t>& layout)
{
	m_Layouts.emplace_back(std::make_tuple(GL_FLOAT, std::get<0>(layout), std::get<1>(layout), std::get<2>(layout)));
	m_Stride += std::get<0>(layout);
}

void VertexArray::ApplyAttribs()
{
	uint32_t type, index, count, offset;
	for (VertexBufferLayout& layout : m_Layouts)
	{
		std::tie(type, index, count, offset) = layout.GetLayout();
		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, count, type, false, m_Stride * GetTypeSizeFromTag(type),
			(const void*)(offset * GetTypeSizeFromTag(type)));
	}
}

void VertexArray::Bind() const
{
	glBindVertexArray(m_RendererID);
}

void VertexArray::Unbind() const
{
	glBindVertexArray(0);
}