#pragma once
#include <iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>

namespace Ionic { namespace Graphics {

		class Window
		{
		public:
			Window(int width, int height, const char * title);
			void Update();
			void Clear();
			void Close();
			bool IsClosed() const;
			~Window();

		private:
			bool _closed;
			int _width, _height;
			const char * _title;
			GLFWwindow * _window;
		private:
			bool Initialize();
		};
	}
}