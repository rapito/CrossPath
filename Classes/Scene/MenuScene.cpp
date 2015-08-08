#include "MenuScene.h"

MenuScene::MenuScene(void)
{

	_title =  new Entity(CommonKeys::keyToString(CommonKeys::IMG_GAME_TITLE));//CCLabelTTF::create("Game Menu", "Arial", 42);
	_background = new Background(CommonKeys::IMG_MENU_BG,CommonKeys::SND_MENU_BG);

	_btnGameStart = CCButton("Game Start");
	_btnOptions = CCButton("Options");
	
	_scene = 0;
}

MenuScene::~MenuScene(void)
{
}

void btnAtnGameStart(GameScene * sender)
{
	CommonCallbacks::navigateToScene(CommonKeys::SCN_LVLSELECT,sender);
}
void btnAtnOptions(GameScene * sender)
{
	CommonCallbacks::navigateToScene(CommonKeys::SCN_OPTIONS,sender);
}

void MenuScene::onEnter()
{
	CCLayer::onEnter();

	if(!CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		this->_background->startBackgroundMusic();
	}
}


void MenuScene::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)touches->anyObject();

	if(_btnGameStart.collidesWith(&touch->getLocation()))
	{
		_btnGameStart.onTriggered();
	}
	else if(_btnOptions.collidesWith(&touch->getLocation()))
	{
		_btnOptions.onTriggered();
	}
	
}
void MenuScene::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent){}
void MenuScene::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent){}

CCScene* MenuScene::getScene()
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
	_btnGameStart.addToScene(this,2);
	_btnOptions.addToScene(this,2);
	
    return _scene;
}

bool MenuScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	_title->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - _title->getContentSize().height));

	_btnGameStart.setPosition(visibleSize.width/2.f,visibleSize.height/2.f);
	_btnOptions.setPosition(_btnGameStart.getPositionX(),_btnGameStart.getPositionY()-(_btnGameStart.getHeight()*1.5f));


	_btnGameStart.assignAction( btnAtnGameStart,(GameScene*)this );
	_btnOptions.assignAction( btnAtnOptions,(GameScene*)this );

	_background->startBackgroundMusic();
    return true;
}
