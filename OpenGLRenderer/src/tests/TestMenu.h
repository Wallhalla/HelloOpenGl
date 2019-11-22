#pragma once
#include "Test.h"
#include <vector>
#include <string>
#include <functional>
#include <iostream>

namespace Test
{
	class TestMenu : public Test
	{
	public:
		TestMenu(Test*& currentTestPtr);
		~TestMenu();

		void OnUpdate(float deltaTime) override;
		void OnRender(const Renderer* renderer = nullptr) override;
		void OnImGuiRender() override;

	private:
		Test*& _currentTest;
		std::vector<std::pair<std::string, std::function<Test*()>>> _tests;

		template<typename T>
		void RegisterTest(const std::string& testName)
		{
			std::cout << "Register Test: " << testName << std::endl;
			_tests.push_back(std::make_pair(testName, []() { return static_cast<Test*>(new T());}));
		}
	};	
}