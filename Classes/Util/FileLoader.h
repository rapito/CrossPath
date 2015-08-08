#pragma once
#include <string>
#include <iostream>

class FileLoader
{
public:
	static FILE* loadFile(std::string filename);
};

