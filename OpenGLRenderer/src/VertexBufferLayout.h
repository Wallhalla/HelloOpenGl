#pragma once
#include <vector>

enum LayoutLocation : unsigned int
{
	POSITION = 0x0,
	TEXCOORD = 0x1
};

enum GlType
{
	FALSE = 0x0,
	TRUE = 0x1,
	UNSIGNED_INT = 0x1405,
	UNSIGNED_BYTE = 0x1401,
	FLOAT = 0x1406
};

struct VertexBufferElement
{
	unsigned int LayoutLocationIndex;
	unsigned int Type;
	unsigned int Count;	
	unsigned int Normalized;

	static unsigned int GetSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GlType::FLOAT:
			return sizeof(float);
		case GlType::UNSIGNED_INT:
			return sizeof(unsigned int);
		case GlType::UNSIGNED_BYTE:
			return sizeof(unsigned char);
		}
		ASSERT(false);
		return 0;
	}
};

class VertexBufferLayout
{
private:
	unsigned int _stride;
	std::vector<VertexBufferElement> _elements;

public:
	VertexBufferLayout()
		:_stride(0)
	{

	}

	template<typename T>
	void Push(LayoutLocation loc, unsigned int count)
	{
		static_assert(false);
	}

	template<>
	void Push<float>(LayoutLocation loc, unsigned int count)
	{
		_elements.push_back({ loc, GlType::FLOAT, count, GlType::FALSE });
		_stride += VertexBufferElement::GetSizeOfType(GlType::FLOAT) * count;
	}

	template<>
	void Push<unsigned int>(LayoutLocation loc, unsigned int count)
	{
		_elements.push_back({ loc, GlType::UNSIGNED_INT, count, GlType::FALSE });
		_stride += VertexBufferElement::GetSizeOfType(GlType::UNSIGNED_INT) * count;
	}

	template<>
	void Push<unsigned char>(LayoutLocation loc, unsigned int count)
	{
		_elements.push_back({ loc, GlType::UNSIGNED_BYTE, count, GlType::TRUE });
		_stride += VertexBufferElement::GetSizeOfType(GlType::UNSIGNED_BYTE) * count;
	}

	inline const std::vector<VertexBufferElement> GetElements() const
	{
		return _elements;
	}

	inline unsigned int GetStride() const
	{
		return _stride;
	}
};