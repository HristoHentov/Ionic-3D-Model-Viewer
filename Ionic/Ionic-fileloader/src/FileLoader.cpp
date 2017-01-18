#include "FileLoader.h"
namespace FileLoader {

	std::string ReadTextFile(const char* path)
	{
		FILE * file = fopen(path, "rt"); // using rt to specify we are reading a text file so we have proper line endings

		fseek(file, 0, SEEK_END);
		unsigned long dataSize = ftell(file);

		char * data = new char[dataSize + 1]; // buffer to save the file data
		memset(data, 0, dataSize); // just to be sure no artifacts are left from all the file manipulation
		fseek(file, 0, SEEK_SET);
		fread(data, 1, dataSize, file);


		fclose(file);

		std::string result(data);
		delete[] data;

		return result;
	}

	bool CheckFile(const char * path)
	{
		struct stat st;
		return stat(path, &st) == 0;
	}
}