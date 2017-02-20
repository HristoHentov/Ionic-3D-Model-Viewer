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
			_logger->LogLine("", TEXT_COLOR_YELLOW);
		}

		void Ionic::Run()
		{

			vec3 lightPosition(5.0f, 12.0f, -5.0f);
			vec3 lightColor(1.0f, 1.0f, 1.0f);


			glClearColor(0.15f, 0.15f, 0.15f, 1.0f);

			FPSCamera camera(1.0f, 0.001f, 1000.0f, 45.0f, float(WINDOW_WIDTH)/ float(WINDOW_HEIGHT));
			Utils::FPSCounter counter;
			Graphics::Model nanosuit("res/nanosuit/nanosuit.obj");

			_shader = new Shader("res/vShader.txt", "res/fShader.txt");
			
			_shader->Build();
			_shader->Enable();

			counter.Start();

			
			///TODO: Calculate an inverse transposed matrix to multiply vertex normals by, so that non-uniform scaling works correctly!
			while (!_appWindow->IsClosed())
			{
				GLfloat currentFrameTime = glfwGetTime();

				counter.Update(currentFrameTime);
				if (counter.NeedsUpdate())
					std::cout << int(counter.GetFPS()) << " fps" << std::endl;

				camera.Update(currentFrameTime);

				_shader->setUniformMat4("model", mat4::Rotation(glfwGetTime(), vec3(0.0f, 1.0f, 0.0f)));
				_shader->setUniformMat4("projection", camera.GetProjection());
				_shader->setUniform2f("mouse_pos", InputManager::GetMousePosition());
				_shader->setUniform3f("lightColor", lightColor);
				_shader->setUniform3f("lightPos", lightPosition);
				_shader->setUniform3f("viewPos", camera.GetPosition());


				if (InputManager::IsKeyPressed(GLFW_KEY_UP))
					lightPosition.y += 0.05;
				if (InputManager::IsKeyPressed(GLFW_KEY_DOWN))
					lightPosition.y -= 0.05;
				if (InputManager::IsKeyPressed(GLFW_KEY_LEFT))
					lightPosition.x -= 0.05;
				if (InputManager::IsKeyPressed(GLFW_KEY_RIGHT))
					lightPosition.x += 0.05;

				if (InputManager::IsKeyPressed(GLFW_KEY_R))
					lightColor = vec3(1.0, 0.4, 0.4);
				if (InputManager::IsKeyPressed(GLFW_KEY_G))
					lightColor = vec3(0.4, 1.0, 0.4);
				if (InputManager::IsKeyPressed(GLFW_KEY_B))
					lightColor = vec3(0.4, 0.4, 1.0);



				GLint viewLoc = glGetUniformLocation(_shader->_programID, "view");
				glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.test));

				_appWindow->Clear();
				nanosuit.Render(*_shader);
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
