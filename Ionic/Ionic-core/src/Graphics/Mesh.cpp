#include "Mesh.h"

namespace Ionic { namespace Graphics {


	Mesh::Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures)
		:Vertices(vertices),Indices(indices),Textures(textures)
	{
		this->BuildMesh();
		std::cout << "Mesh Loaded! V: " << Vertices.size() << " I: " << Indices.size() << std::endl;
		std::cout << "Texutes: " << Textures.size() << std::endl;
	}

	void Mesh::BuildMesh()
	{
		glGenVertexArrays(1, &VAO);
		
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(this->VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, this->Vertices.size() * sizeof(Vertex), &this->Vertices[0], GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->Indices.size() * sizeof(GLuint), &this->Indices[0], GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, Normal));

		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, UV));

		glBindVertexArray(0);
	}


	void Mesh::Render(Shader shader)
	{
		GLuint diffuseCount = 1;
		GLuint specularCount = 1; // will this actually bind to anywhere on the shader, after not having the specular texture slot?

		for (int i = 0; i < this->Textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			std::stringstream ss;
			std::string number;
			std::string name = this->Textures[i].Type;

			if (name == DIFF_TEX_CONVENTION)
				ss << diffuseCount++;
			else if (name == SPEC_TEX_CONVENTION)
				ss << specularCount++;

			number = ss.str();

			shader.setUniform1f(("material." + name + number).c_str(), i);
			glBindTexture(GL_TEXTURE_2D, this->Textures[i].Id);
		}

		glActiveTexture(GL_TEXTURE0);

		glBindVertexArray(this->VAO);
		glDrawElements(GL_TRIANGLES, this->Indices.size(), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

}
}