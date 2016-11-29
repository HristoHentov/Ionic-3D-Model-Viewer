#include "Ionic.h"


namespace Ionic {
	namespace Application {

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
		}

		void Ionic::Run()
		{
			while (!_appWindow->IsClosed())
			{
				_appWindow->Update();
				if (InputManager::IsKeyPressed(GLFW_KEY_SPACE))
				{
					_logger->LogLine("Space pressed!", TEXT_COLOR_YELLOW);
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

				//_logger->LogLine(InputManager::GetMousePosition().c_str(), TEXT_COLOR_YELLOW);

			}
		}

		Ionic::~Ionic()
		{
			delete _appWindow;
		}
	}
}
