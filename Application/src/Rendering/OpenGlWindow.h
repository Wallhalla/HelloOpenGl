#pragma once
#include "Window.h"

struct GLFWwindow;

class OpenGlWindow : public Window
{
public:
	OpenGlWindow(const std::string& title, unsigned int width, unsigned int height);	

	// Geerbt über Window
	virtual std::string GetTitle() const override;
	virtual unsigned int GetWidth() const override;
	virtual unsigned int GetHeight()  const override;	
	virtual void Show() override;

private:
	GLFWwindow* m_Window;

	std::string m_Title;
	unsigned int m_Width;
	unsigned int m_Height;	
};
