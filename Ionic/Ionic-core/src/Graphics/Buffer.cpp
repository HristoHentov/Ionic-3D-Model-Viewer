#include "Buffer.h"


namespace Ionic { namespace Graphics {

		Buffer::Buffer(GLfloat * data, GLshort componentCount, GLsizei size)
			:_componentCount(componentCount)
		{
			glGenBuffers(1, &_bufferID);
			glBindVertexArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
			glBufferData(GL_ARRAY_BUFFER, sizeof(*data) * size, data, GL_STATIC_DRAW);
			glBindVertexArray(0);

		}

		Buffer::Buffer(std::vector<Math::vec3> * data, GLshort componentCount, GLsizei size)
			:_componentCount(componentCount)
		{
			glGenBuffers(1, &_bufferID);
			glBindBuffer(GL_ARRAY_BUFFER, _bufferID);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * componentCount * size, &data, GL_STATIC_DRAW);
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
			glDeleteBuffers(1, &_bufferID);
		}
	}
}
