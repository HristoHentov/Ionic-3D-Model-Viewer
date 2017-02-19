#pragma once
#include <GLEW/glew.h>
#include "../Math/vec3.h"
#include <vector>

namespace Ionic {
	namespace Graphics {
		class Buffer
		{
		public:
			Buffer(GLfloat * data, GLshort componentCount, GLsizei size);
			Buffer(std::vector<Math::vec3> * data, GLshort componentCount, GLsizei size);

			void Enable() const;
			void Disable() const;

			GLuint GetComponentCount() const;
			~Buffer();

		private:
			GLuint _bufferID;
			GLuint _componentCount;
		};
	}
}

