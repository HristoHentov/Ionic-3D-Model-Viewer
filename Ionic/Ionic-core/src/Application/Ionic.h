#pragma once

//#include <iostream>
#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "../Math/IonicMath.h"
#include "../IonicDefinitions.h"
#include "../Logging/ConsoleLogger.h"
#include "../Input/InputManager.h"
#include "../Graphics/Window.h"
#include "../Graphics/Shader.h"
#include "../Graphics/Model.h"
#include "../Utils/FPSCounter.h"
#include "../Graphics/FPSCamera.h"

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
