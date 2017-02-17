#include "IndexBuffer.h"

namespace Ionic { namespace Graphics {

		IndexBuffer::IndexBuffer()
		{
		}

		IndexBuffer::IndexBuffer(GLuint  * data, GLushort size)
			:_size(size)
		{
			glGenBuffers(1, &_bufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * size, data, GL_STATIC_DRAW);
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		IndexBuffer::IndexBuffer(std::vector<unsigned int> * data, GLushort size)
			:_size(size)
		{
			glGenBuffers(1, &_bufferID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * size, &data, GL_STATIC_DRAW);
			//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::Enable() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _bufferID);
		}


		void IndexBuffer::Disable() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		GLuint IndexBuffer::GetSize() const
		{
			return _size;
		}

		IndexBuffer::~IndexBuffer()
		{
			glDeleteBuffers(1, &_bufferID);
		}
	}
}