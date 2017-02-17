#include "Ionic.h"
#include "../Utils/FPSCounter.h"
#include "../Graphics/FPSCamera.h"

#define MODEL
namespace Ionic {
	namespace Application {

		using namespace Math;
		Ionic::Ionic()
		{
			_logger = &_cLogger;
			Initialize();
		}

		void Ionic::Initialize()
		{
			/// Initialize GLFW
			if (!glfwInit())
			{
				_logger->LogLine(GLFW_INIT_FAIL, TEXT_COLOR_RED);
				return;
			}

			/// Create GLFW Window
			_appWindow = new Window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);


			/// Initialize GLEW
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

			_shader = new Shader("src/Graphics/vShader.txt", "src/Graphics/fShader.txt");
			_shader->Build();
			_shader->Enable();

				
			Model nanosuit("../../../nanosuit/nanosuit.obj");


			Utils::FPSCounter counter;
			counter.Start();

			vec3 camPosition(0.0f, 0.0f, 5.0f);
			vec3 camUp(0.0f, 1.0f, 0.0f);
			vec3 camFront(0.0f, 0.0f, -1.0f);


			GLfloat radius = 5.0f;

			GLfloat deltaTime = 0.0f;	// Time between current frame and last frame
			GLfloat lastFrame = 0.0f;

			///Mouse look-around related stuff
			GLfloat yaw = -90.0f;	// Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right (due to how Eular angles work) so we initially rotate a bit to the left.
			GLfloat pitch = 0.0f;
			bool firstMouse = true;
			GLfloat lastX = WINDOW_WIDTH / 2.0;
			GLfloat lastY = WINDOW_HEIGHT / 2.0;

			FPSCamera camera(1.0f, 0.001f, 1000.0f, 45.0f, float(WINDOW_WIDTH)/ float(WINDOW_HEIGHT));

			while (!_appWindow->IsClosed())
			{
				GLfloat currentFrameTime = glfwGetTime();
				deltaTime = currentFrameTime - lastFrame;
				lastFrame = currentFrameTime;

				counter.Update(currentFrameTime);
				if (counter.NeedsUpdate())
					std::cout << "FPS: " << counter.GetFPS() << std::endl;

				camera.Update(currentFrameTime);
				mat4 orbit = mat4::LookAt(camPosition, camPosition + camFront, camUp);
//				mat4 normal = mat4::Translation(vec3(x, y, z));


				_shader->setUniformMat4("model", mat4::Rotation(glfwGetTime() * 5, vec3(0.0f, 1.0f, 0.0f)));
				//_shader->setUniformMat4("view", camera.GetView());
				_shader->setUniformMat4("projection", camera.GetProjection());
				//_shader->setUniformMat4("projection", mat4::Perspective(0.0001f, 1000.0f, 45.0f, float(WINDOW_WIDTH) / float(WINDOW_HEIGHT)));
				_shader->setUniform2f("mouse_pos", InputManager::GetMousePosition());

				GLint viewLoc = glGetUniformLocation(_shader->_programID, "view");
				// Pass the matrices to the shader
				glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(camera.test));

				_appWindow->Clear();
#ifdef MODEL
				nanosuit.Render(*_shader);
				_appWindow->Update();
#endif

				if(InputManager::IsMousePressed(GLFW_MOUSE_BUTTON_1))
				{
					if (firstMouse)
					{
						lastX = InputManager::GetMousePosition().x;
						lastY = InputManager::GetMousePosition().y;
						firstMouse = false;
					}
				
					GLfloat xoffset = InputManager::GetMousePosition().x - lastX;
					GLfloat yoffset = lastY - InputManager::GetMousePosition().y; // Reversed since y-coordinates go from bottom to left
					lastX = InputManager::GetMousePosition().x;
					lastY = InputManager::GetMousePosition().y;
				
					GLfloat sensitivity = 0.05;	// Change this value to your liking
					xoffset *= sensitivity;
					yoffset *= sensitivity;
				
					yaw += xoffset;
					pitch += yoffset;
				
					if (pitch > 89.0f)
						pitch = 89.0f;
					if (pitch < -89.0f)
						pitch = -89.0f;
				
					float rYaw = yaw * (3.1415f / 180.0f);
					float rPitch = pitch * (3.1415f / 180.0f);
					vec3 front;
					front.x = cos(rYaw) * cos(rPitch);
					front.y = sin(rPitch);
					front.z = sin(rYaw) * cos(rPitch);
					camFront = front.Normalize();
				}
				
				

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
