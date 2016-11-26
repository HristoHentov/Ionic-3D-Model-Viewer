#include "Window.h"


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
			return true;
		}



		

	}
}
