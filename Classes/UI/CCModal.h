#pragma once
#include "CCButton.h"
#include <vector>
#include <string>
#include <cocos2d.h>

using namespace std;
//USING_NS_CC;

class LevelScene;
class CCModal : public CCSprite
{
public:
	CCModal(string title, vector<CCButton*> btnVector);
	void addToScene(LevelScene* level);
	void setupPositions();
	void cleanButtonsUp(LevelScene* level);
	virtual void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	~CCModal(void);

private:
	CCLabelTTF* _title;
	vector<CCButton*> _btnVector;
};

