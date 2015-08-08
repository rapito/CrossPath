#pragma once
#include <cocos2d.h>
#include "Level\Logic\Background.h"
#include "Util\CommonKeys.h"

USING_NS_CC;

class GameScene: public CCLayer
{

public:
	GameScene(void);
	~GameScene(void);

    virtual bool init();  
    virtual CCScene* getScene();
	
	CCScene * _scene;
	CCLabelTTF * _title;
	Background * _background;
	
	virtual void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);
};

