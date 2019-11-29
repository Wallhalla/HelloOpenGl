#pragma once
#include "Transform.h"

class Model
{
public:
	Model();	
	~Model();	

	unsigned int GetSize() const;
	void* GetData() const;
	Transform& GetTransform();

private:
	Transform m_transform;
	float* m_Data;
	unsigned int m_Size;
};
