#include "TestTextureSquare.h"

#include "../ShaderProgram.h"
#include "../VertexArray.h"
#include "../VertexBuffer.h"
#include "../IndexBuffer.h"
#include "../Texture.h"
#include "../Renderer.h"
#include "../VertexBufferLayout.h"

#include "gtc/matrix_transform.hpp"

#include "../vendor/imgui/imgui.h"

std::string Test::TestTextureSquare::ClassName = "TestTextureSquare";

Test::TestTextureSquare::TestTextureSquare()
	:_isOrtho(true), _position{ 0.f, 0.f, 200.f }, _camPosition{ 0.f, 0.f, -200.f }, _rotation{ 0.f,0.f,0.f }, _color{ 1.f, 1.f, 1.f, 1.f }
{
	_program = new ShaderProgram("../OpenGLRenderer/res/shaders/Basic.shader");

	float vertices[] = 
	{
		-50.f, -50.f, 0.f, 0.f, // Bottom Left
		50.f, -50.f, 1.f, 0.f, // Bottom Right
		50.f, 50.f, 1.f, 1.f, // Top Right
		-50.f, 50.f, 0.f, 1.f// Top Left
	};

	_vao = new VertexArray();
	_vao->Bind();

	VertexBuffer vbo(vertices, sizeof(vertices));
	VertexBufferLayout layout;
	layout.Push<float>(LayoutLocation::POSITION, 2);
	layout.Push<float>(LayoutLocation::TEXCOORD, 2);

	unsigned int vertexIndices[] =
	{
		0, 1, 2,
		2, 3, 0
	};

	_ibo = new IndexBuffer(vertexIndices, 6);

	_vao->AddBuffer(vbo, layout);
	_vao->Unbind();

	_tex = new Texture("../Assets/Textures/DefaultTexture.jpg");
}

Test::TestTextureSquare::~TestTextureSquare()
{
	delete _program;
	_program = nullptr;
	delete _vao;
	_vao = nullptr;
	delete _ibo;
	_ibo = nullptr;
	delete _tex;
	_tex = nullptr;
}

static float angle = 0.f;

void Test::TestTextureSquare::OnUpdate(float deltaTime)
{
	_program->Bind();
	_program->SetUniform4f("u_Color", _color[0], _color[1], _color[2], _color[3]);

	glm::mat4 proj;

	if (_isOrtho)
	{
		proj = glm::ortho(-Renderer::WindowWidth, Renderer::WindowWidth, -Renderer::WindowHeight, Renderer::WindowHeight, 0.1f, 1000.f);
	}
	else
	{
		proj = glm::perspective<float>(120.f, 960.f / 540.f, 0.1f, 1000.f);
	}

	glm::mat4 camera = glm::lookAt(glm::vec3(-_camPosition[0], _camPosition[1], _camPosition[2]), glm::vec3(-_camPosition[0], _camPosition[1], _camPosition[2] + 500.f), glm::vec3(0.f, 1.f, 0.f));
	glm::mat4 rotation = glm::rotate(glm::mat4(1.f), angle, glm::vec3(0.f, 1.f, 0.f));


	glm::mat4 identity = proj * camera * glm::translate(glm::mat4(1.0f), glm::vec3(_position[0], _position[1], _position[2])) * rotation;
	_program->SetUniformMat4f("u_MVP", identity);

	angle += 0.01f;
	if (angle > 360.f)
	{
		angle = 0.f;
	}
}

void Test::TestTextureSquare::OnRender(const Renderer* renderer)
{
	_tex->Bind();
	renderer->Draw(*_vao, *_ibo, *_program);
	_tex->Unbind();
}

void Test::TestTextureSquare::OnImGuiRender()
{
	ImGui::SliderFloat3("Position", _position, -Renderer::WindowWidth, Renderer::WindowWidth);
	ImGui::SliderFloat3("Camera Position", _camPosition, -Renderer::WindowWidth, Renderer::WindowWidth);
	ImGui::ColorEdit4("Color of Square", _color);
	ImGui::Checkbox("Switch Ortho/Perspective", &_isOrtho);
}
