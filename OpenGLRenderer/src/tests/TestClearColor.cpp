#include "TestClearColor.h"
#include "../OpenGLHeaders.h"
#include "../Renderer.h"
#include "../vendor/imgui/imgui.h"


namespace Test
{
	std::string TestClearColor::ClassName = "TestClearColor";

	TestClearColor::TestClearColor()
		:_color{ 1.f, 0.f, 0.f, 1.0f }
	{
	}

	TestClearColor::~TestClearColor()
	{
	}

	void TestClearColor::OnUpdate(float deltaTime)
	{
	}

	void TestClearColor::OnRender(const Renderer* renderer)
	{
		GLCall(glClearColor(_color[0], _color[1], _color[2], _color[3]));
		GLCall(glClear(GL_COLOR_BUFFER_BIT));
	}

	void TestClearColor::OnImGuiRender()
	{
		ImGui::ColorEdit4("Clear Color", _color);
	}
}