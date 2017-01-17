#pragma once
#include <ostream>

namespace Ionic { namespace Logging {
	
	class Logger
	{
	public:
		virtual void Log(const char * text, int textColor = 15) = 0;
		virtual void LogLine(const char * text, int textColor = 15) = 0;

		virtual void Log(const std::ostream& text, int textColor = 15) = 0;
		virtual void LogLine(const std::ostream& text, int textColor = 15) = 0;

		virtual void Log(std::string text, int textColor = 15) = 0;
		virtual void LogLine(std::string text, int textColor = 15) = 0;
	};
} }
