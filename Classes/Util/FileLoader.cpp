#include "FileLoader.h"

FILE* FileLoader::loadFile(std::string filename)
{
	return fopen(filename.c_str(), "r");

}