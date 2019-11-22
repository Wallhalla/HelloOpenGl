#include "WindowFactory.h"
#include "OpenGlWindow.h"

Window* WindowFactory::CreateWindow(const std::string& title, unsigned int width, unsigned int height)
{
	return new OpenGlWindow(title, width, height);
}
