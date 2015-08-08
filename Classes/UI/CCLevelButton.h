#pragma once
#include "CCButton.h"
#include "..\Level\LevelManager.h"

class CCLevelButton : public CCButton
{
public:

	CCLevelButton(string filename, float x, float y,string nextLevelFile,string title);
	~CCLevelButton(void);
	void addStars(string filename);
	void onTriggered();

private:
	Entity * star[3];
	string _levelTitle;
	string _filename;
	string _nextLevel;
};

