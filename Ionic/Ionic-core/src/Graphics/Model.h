#pragma once
#include <GLEW/glew.h>
#include "Shader.h"
#include "Mesh.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "SOIL/SOIL.h"

namespace Ionic { namespace Graphics {
	class Model
	{
	public:
		Model(GLchar * path);
		void Render(Shader shader);
	private:
		std::vector<Mesh> meshes;
		std::string directory;
		std::vector<Texture> loadedTextures;

		void loadModel(std::string Path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		GLint texFromFile(const char* path, std::string directory); // move to namespace or make static
		std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName);




	};
}
}
