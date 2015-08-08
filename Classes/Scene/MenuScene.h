#pragma once

#include <cocos2d.h>
#include "GameScene.h"
#include "..\UI\CCButton.h"
#include "..\Util\CommonKeys.h"
#include "..\Util\CommonCallbacks.h"

USING_NS_CC;

class MenuScene : public GameScene
{
public:
    Entity* _title;
	MenuScene(void);
	~MenuScene(void);
    CREATE_FUNC(MenuScene);
    virtual CCScene* getScene();
	virtual bool init();
	virtual void onEnter();
	virtual void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);
private:
	CCButton _btnGameStart;
	CCButton _btnOptions;
};

