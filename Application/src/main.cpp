#include "Rendering/Window.h"
#include "Rendering/WindowFactory.h"

int main(void)
{
	Window* window = WindowFactory::CreateWindow("Title", 1920, 1080);	
	
	window->Show();		
	
	delete window;
	window = nullptr;

	return 0;
}