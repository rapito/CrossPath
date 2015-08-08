#pragma once
#include "GameScene.h"
#include "LevelSelectScene.h"
#include "..\UI\CCButton.h"
#include "..\Util\CommonCallbacks.h"

class OptionsScene : public GameScene
{
public:
	OptionsScene(void);
	OptionsScene(GameScene* sceneMenu);
	~OptionsScene(void);
	virtual CCScene* getScene();
	
private:
	CCButton _btnSound;
	CCButton _btnBack;
	GameScene* _sceneMenu;

	virtual bool init();
	virtual void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);
};

