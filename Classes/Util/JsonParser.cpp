#include "JsonParser.h"
#include "FileLoader.h"

void JsonParser::getDocumentFromFile(Document* document, string filename)
{
	FILE * pFile=FileLoader::loadFile(filename);
	assert(pFile!=NULL);
	rapidjson::FileStream text(pFile);	
	document->ParseStream<0>(text);		
	fclose(pFile);
	
}

/*
JsonParser::JsonParser(void)
{
}


JsonParser::~JsonParser(void)
{
}
*/
