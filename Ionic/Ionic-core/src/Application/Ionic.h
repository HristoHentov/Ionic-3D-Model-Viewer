#pragma once

#include <iostream>
#include "../Graphics/Window.h"
#include "../IonicDefinitions.h"
#include "../Logging/Logger.h"
#include "../Logging/ConsoleLogger.h"
#include "../Input/InputManager.h"
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "../Graphics/Shader.h"


namespace Ionic { namespace Application {
		using namespace Graphics;
		using namespace Logging;
		using namespace Input;


		class Ionic
		{
		public:
			Ionic();
			void Initialize();
			void Run();
			~Ionic();

		private:
			Window* _appWindow;
			ConsoleLogger _cLogger;
			Logger * _logger;
			Shader * _shader;
		};

	}
}
