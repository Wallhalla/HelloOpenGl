#include "OpenGLHeaders.h"
#include "Texture.h"
#include "Renderer.h"

#include "vendor/stb_image/stb_image.h"

Texture::Texture(const std::string & filePath)
	:_id(0), _filePath(filePath), _localBuffer(nullptr), _width(0), _height(0), _bitsPerPixel(0)
{	
	const short rgbaChannels = 4;

	// 0-Punkt invertieren, sodass unten links (GL-konform)
	stbi_set_flip_vertically_on_load(true);

	// Image-File laden.
	_localBuffer = stbi_load(_filePath.c_str(), &_width, &_height, &_bitsPerPixel, rgbaChannels);

	GLCall(glGenTextures(1, &_id));
	Bind();

	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
	GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));

	GLCall(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _localBuffer));
	Unbind();

	if (_localBuffer)
	{
		stbi_image_free(_localBuffer);
	}
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &_id));
}

void Texture::Bind(unsigned int slot /*= 0*/) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, _id));
}

void Texture::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
