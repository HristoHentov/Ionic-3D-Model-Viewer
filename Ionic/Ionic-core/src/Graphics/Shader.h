#pragma once
#include <GLEW/glew.h>
#include <iostream>
#include "../../Ionic-fileloader/src/FileLoader.h"
#include "../IonicDefinitions.h"

namespace Ionic { namespace Graphics {

		class Shader
		{
		public:
			Shader(char * vertPath, char * fragPath);
			void Build();
			void Enable() const;
			void Disable() const;

			~Shader();

		private:
			void LoadShader(const char * path, int source , const char * errorMessage);
			void CompileShader(GLuint shaderID, const char * shaderSrc);
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