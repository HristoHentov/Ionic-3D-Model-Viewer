#include "Window.h"
#include "../Input/InputManager.h"


namespace Ionic {
	namespace Graphics {


		Window::Window(int width, int height, const char * title)
		{
			_width = width;
			_height = height;
			_title = title;

			if (!Initialize())
				glfwTerminate();
		}

		void Window::Update()
		{
			glfwSwapBuffers(_window);
			glfwPollEvents();
		}

		bool Window::IsClosed() const
		{
			return this -> _closed;
		}

		Window::~Window()
		{
			glfwDestroyWindow(_window);
			glfwTerminate();
		}

		bool Window::Initialize()
		{
			_window = glfwCreateWindow(_width, _height, _title, nullptr, nullptr);

			if(!_window)
			{
				std::cout << "Error : GLFW failed to create window." << std::endl;
				return false;
			}

			glfwMakeContextCurrent(_window);
			glfwSetWindowUserPointer(_window, this);
			
			glfwSetKeyCallback(_window, Input::InputManager::KeyCallback);
			glfwSetCursorPosCallback(_window, Input::InputManager::MousePositionCallback);
			glfwSetMouseButtonCallback(_window, Input::InputManager::ButtonCallback);
			glfwSetScrollCallback(_window, Input::InputManager::ScrollCallback);
			return true;
		}



		

	}
}
