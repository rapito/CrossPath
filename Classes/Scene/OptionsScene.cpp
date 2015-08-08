#include "OptionsScene.h"

OptionsScene::OptionsScene(void)
{
}

OptionsScene::OptionsScene(GameScene* sceneMenu)
{
	this->_sceneMenu = sceneMenu;

	_title =  CCLabelTTF::create("Options", "Arial", 42);
	_background = new Background(CommonKeys::IMG_MENU_BG,CommonKeys::SND_MENU_BG);
	_btnSound = CCButton("Sound");
	_btnBack = CCButton("Back");
	_scene = 0;
}

OptionsScene::~OptionsScene(void)
{
}

CCScene* OptionsScene::getScene()
{
	if(!_scene)
	{
		_scene = CCScene::create();
		_scene->addChild(this);
	}
	init();
	setTouchEnabled(true);

	
	addChild(_background,0);
	addChild(_title,1);
	_btnBack.addToScene(this,2);
	_btnSound.addToScene(this,2);
    return _scene;
}
void OptionsScene::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)touches->anyObject();

	if(_btnBack.collidesWith(&touch->getLocation()))
	{
		_btnBack.onTriggered();
	}
	else if(_btnSound.collidesWith(&touch->getLocation()))
	{
		_btnSound.onTriggered();
	}
}
void OptionsScene::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent){}
void OptionsScene::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent){}

bool OptionsScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	_title->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - _title->getContentSize().height));

	_btnBack.setPosition(visibleSize.width/2.f,visibleSize.height/2.f);
	_btnSound.setPosition(_btnBack.getPositionX(),_btnBack.getPositionY()-(_btnBack.getHeight()*1.5f));
	
	_btnBack.assignAction(CommonCallbacks::btnAtnBack,(GameScene*) this);
	_btnSound.assignAction(CommonCallbacks::btnAtnSound,(GameScene*)this);
	return true;
}


