#pragma once
#include <GLEW/glew.h>

namespace Ionic { namespace Graphics {
		class IndexBuffer
		{
		public:
			IndexBuffer();
			IndexBuffer(GLushort * data, GLushort size);

			void Enable() const;
			void Disable() const;

			GLuint GetSize() const;
			~IndexBuffer();

		private:
			GLuint _bufferID;
			GLuint _size;
		};
	}
}

