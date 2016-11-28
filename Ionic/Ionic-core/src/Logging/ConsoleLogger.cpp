#include "ConsoleLogger.h"
#include <iostream>
#include "windows.h"

namespace Ionic {
	namespace Logging {
		ConsoleLogger::ConsoleLogger()
		{
		}


		ConsoleLogger::~ConsoleLogger()
		{
		}

		void ConsoleLogger::Log(const char* text, int textColor)
		{
			SetConsoleTextAttribute(consoleHandle, textColor);
			std::cout << text;
		}

		void ConsoleLogger::LogLine(const char* text, int textColor)
		{
			SetConsoleTextAttribute(consoleHandle, textColor);
			std::cout << text << std::endl;
		}
	}
}
