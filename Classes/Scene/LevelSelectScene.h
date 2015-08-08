#pragma once
#include <vector>
#include "GameScene.h"
#include "..\UI\CCButton.h"
#include "..\Util\CommonCallbacks.h"
#include "..\Level\LevelManager.h"

class CCLevelButton;
class LevelSelectScene : public GameScene 
{
public:
	LevelSelectScene(GameScene* sceneMenu);
	~LevelSelectScene(void);
	virtual CCScene* getScene();

private:
	CCButton _btnBack;
	GameScene* _sceneMenu;
	vector<CCLevelButton*> _btnLevelsVector;
	
	virtual bool init();
	virtual bool setLevelButtons();
	virtual void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);

};

