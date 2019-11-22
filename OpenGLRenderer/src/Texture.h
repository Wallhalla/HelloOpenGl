#pragma once
#include <string>

class Texture
{
private:
	unsigned int _id;
	std::string _filePath;
	unsigned char* _localBuffer;
	int _width, _height, _bitsPerPixel;

public:
	Texture(const std::string& filePath);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void Unbind() const;
};