#pragma once

#include "..\Util\JsonParser.h"

#include "..\Util\CommonCallbacks.h"

using namespace std;

class CCLevelButton;
class LevelManager
{
public:
	static LevelManager* getInstance();
	static LevelManager* _instance;
	LevelScene* loadLevel(string filename);
	void initLevelsButtons(vector<CCLevelButton*>* btns, char* archive);
	string getLevelTitle(string filename);
	~LevelManager(void);

private:
	LevelManager(void);
	void assertArchive(Document* archive);
	void assertLevel(Document* level);
	
};

