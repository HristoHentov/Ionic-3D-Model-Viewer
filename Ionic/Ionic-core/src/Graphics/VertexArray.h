#pragma once
#include <GLEW/glew.h>
#include <vector>
#include "Buffer.h"

namespace Ionic {
	namespace Graphics {
		class VertexArray
		{
		public:
			VertexArray();
			~VertexArray();

			void Add(Buffer * buffer, GLuint index);
			void Bind() const;
			void Unbind() const;
		private:
			GLuint _arrayID;
			std::vector<Buffer *> _buffers;
		};
}}
