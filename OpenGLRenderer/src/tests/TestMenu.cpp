#include "../OpenGLHeaders.h"
#include "TestMenu.h"

#include "../vendor/imgui/imgui.h"
#include "TestClearColor.h"
#include "TestTextureSquare.h"
#include "../Renderer.h"

Test::TestMenu::TestMenu(Test *& currentTestPtr)
	:_currentTest(currentTestPtr)
{
	RegisterTest<TestClearColor>(TestClearColor::ClassName);
	RegisterTest<TestTextureSquare>(TestTextureSquare::ClassName);
}

Test::TestMenu::~TestMenu()
{
}

void Test::TestMenu::OnUpdate(float deltaTime)
{
	GLCall(glClearColor(0.f, 0.f, 0.f, 1.f));
}

void Test::TestMenu::OnRender(const Renderer* renderer)
{
}

void Test::TestMenu::OnImGuiRender()
{
	for (auto& test : _tests)
	{
		if (ImGui::Button(test.first.c_str()))
		{
			_currentTest = test.second();
		}
	}
}
