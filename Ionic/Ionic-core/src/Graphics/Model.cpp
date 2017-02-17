#include "Model.h"

namespace Ionic {
	namespace Graphics {

		Model::Model(GLchar* path)
		{
			this->loadModel(path);
		}

		void Model::Render(Shader shader)
		{
			for (int i = 0; i < meshes.size(); ++i)
			{
				this->meshes[i].Render(shader);
			}
		}

		void Model::loadModel(std::string path)
		{
			Assimp::Importer importer;
			const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

			if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
			{
				std::cout << "ERROR! Assimp: " << importer.GetErrorString() << std::endl;
				return;
			}

			this->directory = path.substr(0, path.find_last_of('/'));
			this->processNode(scene->mRootNode, scene);
		}

		void Model::processNode(aiNode* node, const aiScene* scene)
		{
			for (GLuint i = 0; i < node->mNumMeshes; i++)
			{
				aiMesh * mesh = scene->mMeshes[node->mMeshes[i]];
				this->meshes.push_back(this->processMesh(mesh, scene));
			}

			for (GLuint i = 0; i < node->mNumChildren; i++)
			{
				this->processNode(node->mChildren[i], scene);
			}
		}

		Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene)
		{
			std::vector<Vertex> vertices;
			std::vector<GLuint> indices;
			std::vector<Texture> textures;

			for (GLuint i = 0; i < mesh->mNumVertices; i++)
			{
				Vertex vertex;
				vertex.Position = vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
				vertex.Normal = vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

				if (mesh->mTextureCoords[0])
					vertex.UV = vec2(mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y);
				else
					vertex.UV = vec2(0.0f, 0.0f);

				vertices.push_back(vertex);
			}

			for (GLuint i = 0; i < mesh->mNumFaces; i++)
			{
				aiFace face = mesh->mFaces[i];
				for (GLuint c = 0; c < face.mNumIndices; c++)
					indices.push_back(face.mIndices[c]);
			}

			if(mesh->mMaterialIndex >= 0)
			{
				aiMaterial * material = scene->mMaterials[mesh->mMaterialIndex];

				std::vector<Texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, DIFF_TEX_CONVENTION);
				textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

				std::vector<Texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, SPEC_TEX_CONVENTION);
				textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
			}

			return Mesh(vertices, indices, textures);
		}

		std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName)
		{
			std::vector<Texture> textures;

			for (GLuint i = 0; i < mat->GetTextureCount(type); i++)
			{
				aiString str;
				mat->GetTexture(type, i, &str);
				GLboolean skip = false;

				for (GLuint j = 0; j < loadedTextures.size(); j++)
				{
					if (std::strcmp(loadedTextures[j].Path.C_Str(), str.C_Str()) == 0)
					{
						textures.push_back(loadedTextures[j]);
						skip = true;
						break;
					}
				}

				if(!skip)
				{
					Texture texture;
					texture.Id = texFromFile(str.C_Str(), this->directory);
					texture.Type = typeName;
					texture.Path = str;
					textures.push_back(texture);
					this->loadedTextures.push_back(texture);
				}
			}

			return textures;
		}

		GLint Model::texFromFile(const char* path, std::string directory)
		{
			std::string filename = std::string(path);
			filename = directory + '/' + filename;
			GLuint textureID;
			glGenTextures(1, &textureID);
			int width, height;
			unsigned char* image = SOIL_load_image(filename.c_str(), &width, &height, 0, SOIL_LOAD_RGB);
			// Assign texture to ID
			glBindTexture(GL_TEXTURE_2D, textureID);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
			glGenerateMipmap(GL_TEXTURE_2D);

			// Parameters
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glBindTexture(GL_TEXTURE_2D, 0);
			SOIL_free_image_data(image);
			return textureID;
		}




	}
}