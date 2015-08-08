#include "LevelSelectScene.h"
#include "..\UI\CCLevelButton.h"

LevelSelectScene::LevelSelectScene(GameScene* sceneMenu)
{
	this->_sceneMenu = sceneMenu;

	_title =  CCLabelTTF::create("Level Select", "Arial", 42);
	_background = new Background(CommonKeys::IMG_MENU_BG,CommonKeys::SND_MENU_BG);
	_btnBack = CCButton("Back");
	_scene = 0;
}

LevelSelectScene::~LevelSelectScene(void)
{

}


void LevelSelectScene::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)touches->anyObject();
	CCButton *touchedBut = 0;
	if(_btnBack.collidesWith(&touch->getLocation()))
	{
		touchedBut = &_btnBack;
	}
	else
	{
		for(int i = 0 ; i<(int)_btnLevelsVector.size();i++)
		{
			CCButton* but = _btnLevelsVector[i];
			if (but->collidesWith(&touch->getLocation()))
			{
				touchedBut = but;
				i = (int)_btnLevelsVector.size()+1;
			}
		}
	}
	if(touchedBut)
	{
		touchedBut->onTriggered();
	}

}
void LevelSelectScene::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent){}
void LevelSelectScene::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent){}

CCScene* LevelSelectScene::getScene()
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
	
    return _scene;
}


bool LevelSelectScene::setLevelButtons()
{
	_btnLevelsVector = vector<CCLevelButton*>();
	LevelManager::getInstance()->initLevelsButtons(&_btnLevelsVector,"LevelArchive.CPLA");
	
	for(int i = 0 ; i<(int)_btnLevelsVector.size();i++)
	{
		CCButton* but = _btnLevelsVector[i];
		but->addToScene(this,2);
	}
	return true;
}


bool LevelSelectScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	_title->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - _title->getContentSize().height));
	
	_btnBack.setPosition(_btnBack.getRect()->getMaxX()*2,visibleSize.height-_btnBack.getRect()->getMaxY());
	_btnBack.assignAction(CommonCallbacks::btnAtnBack,(GameScene*) this);

	if(!setLevelButtons())
		_btnBack.setColor(ccc3(20,25,30));
	

	return true;
}
