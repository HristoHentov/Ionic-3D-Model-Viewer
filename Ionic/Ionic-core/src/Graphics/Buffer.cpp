#include "Buffer.h"

namespace Ionic { namespace Graphics {

		Buffer::Buffer(GLfloat * data, GLshort componentCount, GLsizei size)
			:_componentCount(componentCount)
		{
			glGenBuffers(1, &_bufferID);
			glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * size, data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Buffer::Enable() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
		}


		void Buffer::Disable() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		GLuint Buffer::GetComponentCount() const
		{
			return _componentCount;
		}

		Buffer::~Buffer()
		{
			
		}
	}
}