#include "Ionic.h"
#include "../Math/vec4.h"
#include "../Math/mat2.h"
#include "../Math/mat3.h"
#include "../Math/mat4.h"


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
			while (!_appWindow->IsClosed())
			{
				_appWindow->Update();
				if (InputManager::IsKeyPressed(GLFW_KEY_SPACE))
				{
					Math::vec4 x = Math::vec4(1.0f, 2.0f, 3.0f, 4.0f);
					Math::vec4 y = Math::vec4(1.0f, 2.0f, 3.0f, 4.0f);
					y += Math::vec4(1.0f, 1.0f, 1.0f, 1.0f);

					Math::vec4 z = x + y;
					std::cout << "=================" << std::endl;
					std::cout << "x: " << x << std::endl;
					std::cout << "y: " << y << std::endl;
					std::cout << "z: " << z << std::endl;
					std::cout << "-----------------" << std::endl;
					z -= Math::vec4(1.0f, 1.0f, 1.0f, 1.0f);
					std::cout << "x: " << x << std::endl;
					std::cout << "y: " << y << std::endl;
					std::cout << "z: " << z << std::endl;

					std::cout << "=================" << std::endl;

				}
				if(InputManager::IsMousePressed(GLFW_MOUSE_BUTTON_MIDDLE))
				{
					_logger->LogLine("Scroll pressed!", TEXT_COLOR_GREEN);
				}
				if(InputManager::GetScrollOffset() != 0)
				{
					_logger->Log("Scroll Offset: ", TEXT_COLOR_RED);
					_logger->LogLine(std::to_string(InputManager::GetScrollOffset()).c_str());
				}
				if(InputManager::IsKeyPressed(GLFW_KEY_M))
				{
					system("CLS");
					mat4 test(1.0f);
					//test = mat4::Rotation(45, vec3(0, 1, 0));
					test = mat4::Scale(vec3(2, 3, 4)) * mat4::Identity();
					test *= mat4(1.0f);
					for (int r = 0; r < 4; r++)
					{
						for (int c = 0; c < 4; c++)
						{
							std::cout << test.elements[r * 4 + c] << " ";
						}

						std::cout << std::endl;
					}
					
					std::cout << "=============END=============" << std::endl;

				}

		
				//_logger->LogLine(InputManager::GetMousePosition().c_str(), TEXT_COLOR_YELLOW);

			}
		}

		Ionic::~Ionic()
		{
			delete _appWindow;
		}
	}
}
