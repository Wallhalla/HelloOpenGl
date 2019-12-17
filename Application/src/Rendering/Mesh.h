#pragma once

class Mesh
{
public:
	virtual void Bind() const = 0;
	virtual void Unbind() const = 0;
	virtual void Draw() const = 0;
};