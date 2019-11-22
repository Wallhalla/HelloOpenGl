#pragma once

class Renderer;

namespace Test
{
	class Test
	{
	public:
		Test(){}
		virtual ~Test(){}

		virtual void OnUpdate(float deltaTime) {}
		virtual void OnRender(const Renderer* renderer = nullptr){}
		virtual void OnImGuiRender(){}		
	};
}