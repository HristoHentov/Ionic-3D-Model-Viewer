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

			_logger->LogLine(INIT_SUCCSESS, TEXT_COLOR_GREEN);
			_logger->Log(OPENGL_VERSION);
			_logger->LogLine((char*)glGetString(GL_VERSION), TEXT_COLOR_GREEN);
			_logger->Log(OPENGL_GPU);
			_logger->LogLine((char*)glGetString(GL_RENDERER), TEXT_COLOR_GREEN);
		}

		void Ionic::Run()
		{


			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

			FPSCamera camera(1.0f, 0.001f, 1000.0f, 45.0f, float(WINDOW_WIDTH)/ float(WINDOW_HEIGHT));
			Utils::FPSCounter counter;
			Graphics::Model nanosuit("../../../nanosuit/nanosuit.obj");

			_shader = new Shader("src/Graphics/vShader.txt", "src/Graphics/fShader.txt");
			
			_shader->Build();
			_shader->Enable();

			counter.Start();

			while (!_appWindow->IsClosed())
			{
				GLfloat currentFrameTime = glfwGetTime();

				counter.Update(currentFrameTime);
				if (counter.NeedsUpdate())
					std::cout << "FPS: " << counter.GetFPS() << std::endl;

				camera.Update(currentFrameTime);

				_shader->setUniformMat4("model", mat4::Rotation(glfwGetTime() * 5, vec3(0.0f, 1.0f, 0.0f)));
				_shader->setUniformMat4("projection", camera.GetProjection());
				_shader->setUniform2f("mouse_pos", InputManager::GetMousePosition());

				///Had to use GLM and default way of setting uniform matrix due to a bug with my LookAt Matrix.
				GLint viewLoc = glGetUniformLocation(_shader->_programID, "view");
				glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.test));

				_appWindow->Clear();
				nanosuit.Render(*_shader);
				_appWindow->Update();			

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
