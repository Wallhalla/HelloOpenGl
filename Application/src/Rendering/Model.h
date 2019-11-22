#pragma once

class Model
{
public:
	Model();	

	unsigned int GetSize() const;
	void* GetData() const;

private:
	float* m_Data;
	unsigned int m_Size;
};
