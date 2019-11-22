#pragma once
#include "Test.h"
#include <string>

class ShaderProgram;
class VertexArray;
class IndexBuffer;
class Texture;

namespace Test
{
	class TestTextureSquare : public Test
	{
	public:
		static std::string ClassName;

		TestTextureSquare();
		~TestTextureSquare();

		void OnUpdate(float deltaTime) override;
		void OnRender(const Renderer* renderer = nullptr) override;
		void OnImGuiRender() override;

	private:		
		ShaderProgram* _program;
		VertexArray* _vao;
		IndexBuffer* _ibo;
		Texture* _tex;	

		float _position[3];
		float _camPosition[3];
		float _rotation[3];
		float _color[4];
		bool _isOrtho;
	};
}