#include "hzpch.h"
#include "Shader.h"

#include "glad/glad.h"

namespace Hazel
{
	Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		// Creating VERTEX Shader obj
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Set the source code of shader to the Shader obj
		const GLchar* src = vertexSrc.c_str();
		glShaderSource(vertexShader, 1, &src, 0);

		// Compiled Shader
		glCompileShader(vertexShader);

		// Checking for Compilation Status
		GLint success = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE) {

			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			char* infoLog = new char[maxLength]; // runtime stack allocation
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, infoLog);

			glDeleteShader(vertexShader);

			HZ_CORE_ERROR("{0}", infoLog);
			HZ_CORE_ASSERT(false, "Vertex Shader Compilation Failere!");
			return;
		}

		// Creating FRAGMENT Shader obj
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		src = fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &src, 0);

		glCompileShader(fragmentShader);


		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE) {
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			char* infoLog = new char[maxLength];
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, infoLog);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			
			HZ_CORE_ERROR("{0}", infoLog);
			HZ_CORE_ASSERT(false, "Fragment Shader Compilation Failere!");
			return;
		}

		m_RendererID = glCreateProgram();
		GLuint program = m_RendererID;

		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		// Linking
		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, &isLinked);
		if (isLinked == GL_FALSE) {
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, infoLog.data());

			glDeleteProgram(program);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
			
			HZ_CORE_ERROR("{0}", infoLog.data());
			HZ_CORE_ASSERT(false, "Shader Link Failere!");
			return;
		}
		
		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_RendererID);
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}
}
