#include "Ionic.h"

namespace Ionic {
	namespace Application {

		using namespace Math;
		Ionic::Ionic()
			:_logger(&_cLogger)
		{
			Initialize();
		}

		void Ionic::Initialize()
		{
			if (!glfwInit())
			{
				_logger->LogLine(GLFW_INIT_FAIL, TEXT_COLOR_RED);
				return;
			}

			_appWindow = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

			if (glewInit() != GLEW_OK)
			{

				_logger->LogLine(GLEW_INIT_FAIL, TEXT_COLOR_RED);
				_logger->LogLine((char *)glewGetErrorString(glewInit()), TEXT_COLOR_RED);

				return;
			}
			glewExperimental = true;
			
			if (!_config.VSync)
				glfwSwapInterval(0);

			_logger->LogLine(INIT_SUCCSESS, TEXT_COLOR_GREEN);
			_logger->Log(OPENGL_VERSION);
			_logger->LogLine((char*)glGetString(GL_VERSION), TEXT_COLOR_GREEN);
			_logger->Log(OPENGL_GPU);
			_logger->LogLine((char*)glGetString(GL_RENDERER), TEXT_COLOR_GREEN);
			_logger->LogLine("", TEXT_COLOR_YELLOW);
		}

		void Ionic::Run()
		{
			glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

			Entities::FPSCamera camera(25.0f, 0.001f, 1000.0f, 45.0f, float(WINDOW_WIDTH)/ float(WINDOW_HEIGHT));
			Entities::Light keyLight(vec3(5.0f, 12.0f, 10.0f));
			Utils::FPSCounter counter;
			Graphics::Model nanosuit(const_cast<GLchar*>(_config.Model.c_str()));

			Shader shader(&_config.VShader[0], &_config.FShader[0]);
			
			shader.Build();
			shader.Enable();

			counter.Start();

			
			///TODO: Calculate an inverse transposed matrix to multiply vertex normals by, so that non-uniform scaling works correctly!
			while (!_appWindow->IsClosed())
			{
				GLfloat currentFrameTime = glfwGetTime();

				///TODO: These will eventually all inherit GenericEntity or something, and will be polymoprhicly called.
				counter.Update(currentFrameTime);
				camera.Update(currentFrameTime);
				keyLight.Update(currentFrameTime);

				if (counter.NeedsUpdate())
					std::cout << int(counter.GetFPS()) << " fps" << std::endl;

				shader.setUniformMat4("model", mat4::Rotation(glfwGetTime(), vec3(0.0f, 1.0f, 0.0f)));
				shader.setUniformMat4("projection", camera.GetProjection());
				shader.setUniform2f("mouse_pos", InputManager::GetMousePosition());
				shader.setUniform3f("lightColor", keyLight.Color);
				shader.setUniform3f("lightPos", keyLight.Position);
				shader.setUniform3f("viewPos", camera.GetPosition() + camera.GetDirection());

				GLint viewLoc = glGetUniformLocation(shader._programID, "view");
				glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.test));

				_appWindow->Clear();
				nanosuit.Render(shader);
				_appWindow->Update();		

				if (InputManager::IsKeyPressed(GLFW_KEY_1))
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				if (InputManager::IsKeyPressed(GLFW_KEY_2))
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				if (InputManager::IsKeyPressed(GLFW_KEY_ESCAPE))
				{
					_appWindow->Close();
				}
			}
		}

		Ionic::~Ionic()
		{
			delete _appWindow;
		}
	}
}
