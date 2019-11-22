#pragma once
#include <string>

class Window;

class WindowFactory
{
public:
	static Window* CreateWindow(const std::string& title, unsigned int width, unsigned int height);
};