#pragma once
#include "Transform.h"

class Model
{
public:
	Model();	
	~Model();	

	Transform& GetTransform();

private:
	Transform m_transform;	
};
