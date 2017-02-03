#pragma once
#include <GLEW/glew.h>
#include <iostream>
#include "../../Ionic-fileloader/src/FileLoader.h"
#include "../IonicDefinitions.h"
#include "../Math/IonicMath.h"
#include <vector>

namespace Ionic { namespace Graphics {

		class Shader
		{
		public:
			Shader(char * vertPath, char * fragPath);
			void Build();
			void Enable() const;
			void Disable() const;

			GLint GetULocation(const GLchar* uName) const;
			
			void setUniform1i(const GLchar* uName, int data) const;
			void setUniform1f(const GLchar* uName, float data) const;
			void setUniform2f(const GLchar* uName, const Math::vec2& data) const;
			void setUniform3f(const GLchar* uName, const Math::vec3& data) const;
			void setUniform4f(const GLchar* uName, const Math::vec4& data) const;
			void setUniformMat4(const GLchar* uName, const Math::mat4& data) const;

			~Shader();

		private:
			void BuildShader(GLuint shaderID, const char * path, const char * source, char * errorMessage);
			void ClearShader(GLuint programID, GLuint shaderID);
			const char * _vertexSource;
			const char * _fragmentSource;
			const char * _vPath;
			const char * _fPath;
			GLuint _vShaderID;
			GLuint _fShaderID;
			GLuint _programID;
		};
}}