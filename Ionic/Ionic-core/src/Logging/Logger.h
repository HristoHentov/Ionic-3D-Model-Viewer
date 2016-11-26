#pragma once

namespace Ionic { namespace Logging {
	
	class Logger
	{
	public:
		virtual void Log(const char * text, int textColor = 15) = 0;
		virtual void LogLine(const char * text, int textColor = 15) = 0;
	};
} }
