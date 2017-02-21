#include "Config.h"
#include "../IonicDefinitions.h"
#include "../../Ionic-fileloader/src/FileLoader.h"

namespace Ionic {
	namespace Utils {
		Config::Config()
		{
			std::string config = FileLoader::ReadTextFile(IONIC_CFGFILE);

			this->Model = GetValue(config, true);
			this->VShader = GetValue(config, false);
			this->FShader = GetValue(config, false);
			this->VSync = GetValue(config, false) == "1" ? true : false;
		}

		std::string Config::GetValue(std::string &cfg, bool first)
		{
			if (!first)
				cfg = cfg.substr(cfg.find_first_of("\n") + 1);
			
			std::string line = cfg.substr(0, cfg.find_first_of("\n"));
			int index = line.find_first_of('\"');
			return line.substr(index + 1, line.length() - index - 2);
		}
	}
}