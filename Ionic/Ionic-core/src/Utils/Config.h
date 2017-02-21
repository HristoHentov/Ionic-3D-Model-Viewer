#pragma once
#include <string>
namespace Ionic {
	namespace Utils {
		class Config
		{
		public:
			Config();

			std::string Model;
			std::string VShader;
			std::string FShader;
			bool VSync = false;
		private:
			static std::string GetValue(std::string &cfg, bool first);
		};

	}
}