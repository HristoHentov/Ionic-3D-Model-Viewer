#include "VertexArray.h"


namespace Ionic {
	namespace Graphics {

		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &_arrayID);
		}


		void VertexArray::Add(Buffer* buffer, GLuint index)
		{
			Bind();
			buffer->Enable();
			glVertexAttribPointer(index, buffer->GetComponentCount(), GL_FLOAT, GL_FALSE,0, 0);
			glEnableVertexAttribArray(index);

			buffer->Disable();
			Unbind();
		}

		void VertexArray::Bind() const
		{
			glBindVertexArray(_arrayID);
		}

		void VertexArray::Unbind() const
		{
			glBindVertexArray(0);
		}




		VertexArray::~VertexArray()
		{
			for (int i = 0; i < _buffers.size(); i++)
			{
				delete _buffers[i];
			}
		}
	}
}
