#pragma once
#include <vector>
#include "VertexArrayObject.h"

class Model;

class Scene
{
public:
	void AddModel(Model* model);
	void RemoveModel(Model* model);

	void DrawScene();
};