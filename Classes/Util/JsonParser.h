#pragma once
#include <string>
#include "..\rapidjson\document.h"
#include "..\rapidjson\filestream.h"

using std::string;

using rapidjson::Document;
using rapidjson::FileStream;
using rapidjson::Value;
using rapidjson::SizeType;

class JsonParser
{
public:
	static void getDocumentFromFile(Document* document, string filename);
};

