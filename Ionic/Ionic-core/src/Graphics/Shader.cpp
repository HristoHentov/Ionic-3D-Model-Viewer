#include "Shader.h"

namespace Ionic {
	namespace Graphics {

		Shader::Shader(char* vertPath, char* fragPath)
			:_vPath(vertPath), _fPath(fragPath)
		{
			_programID = glCreateProgram();
			_vShaderID = glCreateShader(GL_VERTEX_SHADER);
			_fShaderID = glCreateShader(GL_FRAGMENT_SHADER);
		}

		void Shader::Build()
		{
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

		GLint Shader::GetULocation(const GLchar* uName) const
		{
			return glGetUniformLocation(_programID, uName);
		}

		void Shader::setUniform1i(const GLchar* uName, int data) const
		{
			glUniform1i(GetULocation(uName), data);
		}

		void Shader::setUniform1f(const GLchar* uName, float data) const
		{
			glUniform1i(GetULocation(uName), data);

		}

		void Shader::setUniform2f(const GLchar* uName, const Math::vec2& data) const
		{
			glUniform2f(GetULocation(uName), data.x, data.y);

		}

		void Shader::setUniform3f(const GLchar* uName, const Math::vec3& data) const
		{
			glUniform3f(GetULocation(uName), data.x, data.y, data.z);

		}

		void Shader::setUniform4f(const GLchar* uName, const Math::vec4& data) const
		{
			glUniform4f(GetULocation(uName), data.x, data.y, data.z, data.w);

		}

		void Shader::setUniformMat4(const GLchar* uName, const Math::mat4& data) const
		{
			glUniformMatrix4fv(GetULocation(uName), 1, GL_FALSE, data.elements);
		}

		Shader::~Shader()
		{

		}

	}
}
