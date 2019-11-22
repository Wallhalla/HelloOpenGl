#pragma once
#include "Test.h"

namespace Test
{
	class TestClassTemplate : public Test
	{
	public:
		TestClassTemplate();
		~TestClassTemplate();

		void OnUpdate(float deltaTime) override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}