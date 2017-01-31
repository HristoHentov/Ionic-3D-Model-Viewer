#pragma once
#include <GLEW/glew.h>

namespace Ionic { namespace Graphics {
class Buffer
{
public:
	Buffer(GLfloat * data, GLshort componentCount, GLsizei size);
	
	void Enable() const;
	void Disable() const;
	
	GLuint GetComponentCount() const;
	~Buffer();

	private:
		GLuint _bufferID;
		GLuint _componentCount;
};
}}

