#pragma once

#ifdef DEBUG
#define ASSERT(x) if(!(x)) __debugbreak();
#else
#define ASSERT(x) x
#endif

#ifdef DEBUG
#define GLCall(x)\
Renderer::GLClearErrors();\
x;\
ASSERT(Renderer::GLLogCall(#x, __FILE__, __LINE__));
#else
#define GLCall(x) x
#endif

struct GLFWwindow;
class VertexArray;
class IndexBuffer;
class ShaderProgram;

class Renderer
{
private:
	GLFWwindow* _window;

public:
	static float WindowWidth, WindowHeight;

	static void GLClearErrors();
	static bool GLLogCall(const char* function, const char* file, int line);

	int Init();
	unsigned int CreateWindow();
	void CreateContext();
	bool IsClosing();
	void Clear();	
	void Draw(const VertexArray& vao, const IndexBuffer& ibo, const ShaderProgram& shaderProgram) const;
	void Swap();
	void Poll();
	void Terminate();
};
