#pragma once
#include "Test.h"
#include <string>

namespace Test
{
	class TestClearColor : public Test
	{
	public:
		TestClearColor();
		~TestClearColor();

		void OnUpdate(float deltaTime) override;
		void OnRender(const Renderer* renderer = nullptr) override;
		void OnImGuiRender() override;
	
		static std::string ClassName;

	private:
		float _color[4];
	};
}