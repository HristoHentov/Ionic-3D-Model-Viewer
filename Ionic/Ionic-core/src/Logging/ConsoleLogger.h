#pragma once
#include "Logger.h"
#include "windows.h"
#include <iostream>


namespace Ionic { namespace Logging {

	class ConsoleLogger : public Logger
		{
		public:
			ConsoleLogger();
			void Log(const char * text, int textColor = 15) override;
			void LogLine(const char * text, int textColor = 15) override;
			void Log(const std::ostream& text, int textColor = 15) override;
			void LogLine(const std::ostream& text, int textColor = 15) override;

			~ConsoleLogger();

		private:
			HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		};

	}
}
