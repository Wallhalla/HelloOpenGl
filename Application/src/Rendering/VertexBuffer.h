#pragma once

class VertexBuffer
{	
public:
	virtual void Bind() = 0;
	virtual void Unbind() = 0;
};