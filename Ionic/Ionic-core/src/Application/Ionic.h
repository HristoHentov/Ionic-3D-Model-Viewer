#pragma once

#include <iostream>
#include "../Graphics/Window.h"
#include "../IonicDefinitions.h"
#include "../Logging/Logger.h"
#include "../Logging/ConsoleLogger.h"

using namespace Ionic::Graphics;
using namespace Ionic::Logging;

namespace Ionic {
	namespace Application {
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
		};

	}
}