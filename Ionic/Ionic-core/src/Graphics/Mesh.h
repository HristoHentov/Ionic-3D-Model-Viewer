#pragma once
#include "../Math/IonicMath.h"
#include <GLEW/glew.h>
#include <vector>
#include "Shader.h"
#include <assimp/types.h>

using namespace Ionic::Math;
namespace Ionic {
	namespace Graphics {

		struct Vertex
		{
			vec3 Position;
			vec3 Normal;
			vec2 UV;
		};

		struct Texture
		{
			GLuint Id;
			std::string Type;
			aiString Path;
		};


		class Mesh
		{
		public:
			std::vector<Vertex> Vertices;
			std::vector<GLuint> Indices;
			std::vector<Texture> Textures;

			Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
			void Render(Shader shader);
		private:
			GLuint VAO, VBO, EBO;
			void BuildMesh();
		};



	}
}
