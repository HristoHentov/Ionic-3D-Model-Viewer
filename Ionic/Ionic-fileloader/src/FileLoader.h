#pragma once
#include <string>
namespace FileLoader {

	std::string ReadTextFile(const char * path);
	bool CheckFile(const char * path);
}