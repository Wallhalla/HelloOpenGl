#include "OpenGLHeaders.h"
#include "VertexArray.h"
#include "Renderer.h"

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

VertexArray::VertexArray()
{
	GLCall(glCreateVertexArrays(1, &_id));	
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &_id));
}

void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexBufferLayout& layout)
{	
	buffer.Bind();
	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];

		// Set/Enable the Layout Location inside the Shader we refer this buffer to.
		unsigned int layoutIndex = element.LayoutLocationIndex;
		GLCall(glEnableVertexAttribArray(layoutIndex));
		GLCall(glVertexAttribPointer(layoutIndex, element.Count, element.Type, element.Normalized, layout.GetStride(), (const void*)offset));
		offset += element.Count * VertexBufferElement::GetSizeOfType(element.Type);
	}	

	buffer.Unbind();
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(_id));	
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}
