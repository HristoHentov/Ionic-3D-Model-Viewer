#pragma once
#include <GLEW/glew.h>
#include <vector>
#include "../Math/vec3.h"
namespace Ionic { namespace Graphics {
		class IndexBuffer
		{
		public:
			IndexBuffer();
			IndexBuffer(GLuint * data, GLushort size);
			IndexBuffer(std::vector<unsigned int> * data, GLushort size);

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

