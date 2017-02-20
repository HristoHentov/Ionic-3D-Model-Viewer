#include "Window.h"
#include "../Input/InputManager.h"

namespace Ionic { namespace Graphics {
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

		void Window::Clear()
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::IsClosed() const
		{
			return this -> _closed;
		}

		void Window::Close()
		{
			this->_closed = true;
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

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);


			//glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

			glfwMakeContextCurrent(_window);
			glfwSetWindowUserPointer(_window, this);

			glfwSwapInterval(0);
			glEnable(GL_DEPTH_TEST);
			//glEnable(GL_CULL_FACE);
			//glCullFace(GL_BACK);
			//glDepthFunc(GL_LESS);


			
			glfwSetKeyCallback(_window, Input::InputManager::KeyCallback);
			glfwSetCursorPosCallback(_window, Input::InputManager::MousePositionCallback);
			glfwSetMouseButtonCallback(_window, Input::InputManager::ButtonCallback);
			glfwSetScrollCallback(_window, Input::InputManager::ScrollCallback);
			return true;
		}
	}
}
