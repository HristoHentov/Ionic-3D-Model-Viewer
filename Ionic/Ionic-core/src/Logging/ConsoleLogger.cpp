#include "ConsoleLogger.h"


namespace Ionic {
	namespace Logging {
		ConsoleLogger::ConsoleLogger()
		{
		}

		ConsoleLogger::~ConsoleLogger()
		{
		}
		void ConsoleLogger::Log(std::string text, int textColor)
		{
			SetConsoleTextAttribute(consoleHandle, textColor);
			std::cout << text;
		}

		void ConsoleLogger::LogLine(std::string text, int textColor)
		{
			SetConsoleTextAttribute(consoleHandle, textColor);
			std::cout << text << std::endl;
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

		void ConsoleLogger::Log(const std::ostream& text, int textColor)
		{
			SetConsoleTextAttribute(consoleHandle, textColor);
			std::cout << &text;
		}

		void ConsoleLogger::LogLine(const std::ostream& text, int textColor)
		{
			SetConsoleTextAttribute(consoleHandle, textColor);
			std::cout << &text;
		}
	}
}
