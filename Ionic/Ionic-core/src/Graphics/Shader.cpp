#include "Shader.h"
#include <vector>

namespace Ionic {
	namespace Graphics {

		Shader::Shader(char* vertPath, char* fragPath)
		{
			_programID = glCreateProgram();
			_vShaderID = glCreateShader(GL_VERTEX_SHADER);
			_fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
			_vPath = vertPath;
			_fPath = fragPath;
		}

		void Shader::Build()
		{
			//LoadShader(_vPath, 1, VSHADER_PATH_FAIL);
			//LoadShader(_fPath, 2, FSHADER_PATH_FAIL);
			//
			//CompileShader(_vShaderID, _vertexSource);
			//CompileShader(_fShaderID, _fragmentSource);

			BuildShader(_vShaderID, _vPath, _vertexSource, VSHADER_PATH_FAIL);
			BuildShader(_fShaderID, _fPath, _fragmentSource, FSHADER_PATH_FAIL);

			glAttachShader(_programID, _vShaderID);
			glAttachShader(_programID, _fShaderID);
			glLinkProgram(_programID);

			GLint linkResult;
			glGetProgramiv(_programID, GL_LINK_STATUS, &linkResult);

			if (linkResult == GL_FALSE)
			{
				GLint logLength = 0;
				glGetProgramiv(_programID, GL_INFO_LOG_LENGTH, &logLength);
				std::vector<char> errorMessage(logLength);
				std::cout << &errorMessage[0] << std::endl;
			}

			ClearShader(_programID, _vShaderID);
			ClearShader(_programID, _fShaderID);

		}
		void Shader::LoadShader(const char* path, int source, const char * errorMessage = "")
		{
			/*if (!FileLoader::CheckFile(path)) // implement proper logging here
				std::cout << errorMessage;

			if (source == 1)
			{
				dataBuffer = FileLoader::ReadTextFile(path);
				_vertexSource = dataBuffer.c_str();
			}
			else if (source == 2)
			{
				dataBuffer = FileLoader::ReadTextFile(path);
				_fragmentSource = dataBuffer.c_str();
			} */
		}

		void Shader::CompileShader(GLuint shaderID, const char * shaderSrc)
		{
			GLint result = GL_FALSE;
			GLint logSize = 0;
			glShaderSource(shaderID, 1, &shaderSrc, NULL);
			glCompileShader(shaderID);

			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logSize);
				std::vector<char> errorLog(logSize);
				glGetShaderInfoLog(shaderID, logSize, &logSize, &errorLog[0]);
				std::cout << &errorLog[0] << std::endl;
				glDeleteShader(shaderID);
			}
		}

		void Shader::BuildShader(GLuint shaderID, const char* path, const char* source, char* errorMessage)
		{
			if (!FileLoader::CheckFile(path)) // implement proper logging here
				std::cout << errorMessage;
			std::string srcBuff = FileLoader::ReadTextFile(path);
			source = srcBuff.c_str();

			GLint result = GL_FALSE;
			GLint logSize = 0;
			glShaderSource(shaderID, 1, &source, NULL);
			glCompileShader(shaderID);

			glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);

			if (result == GL_FALSE)
			{
				glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logSize);
				std::vector<char> errorLog(logSize);
				glGetShaderInfoLog(shaderID, logSize, &logSize, &errorLog[0]);
				std::cout << &errorLog[0] << std::endl;
				glDeleteShader(shaderID);
			}

		}

		void Shader::ClearShader(GLuint programID, GLuint shaderID)
		{
			glDetachShader(programID, shaderID);
			glDeleteShader(shaderID);
		}

		void Shader::Enable() const
		{
			glUseProgram(_programID);
		}

		void Shader::Disable() const
		{
			glUseProgram(NULL);
		}
		Shader::~Shader()
		{

		}

	}
}
