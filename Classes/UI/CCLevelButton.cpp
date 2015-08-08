#include "CCLevelButton.h"


CCLevelButton::CCLevelButton(string filename,float x,float y,string nextLevel, string title)
{
	
	int extensionIndex = filename.find(".");
	string label = filename.substr(0,extensionIndex);
	_filename = filename;
	_nextLevel = nextLevel;
	_levelTitle=title;
	_levelTitle.replace(_levelTitle.find(" "),1,"_");//.replace(" ",1,"_");
	initButton(label,CommonKeys::keyToString(CommonKeys::IMG_BTN_LEVEL));
	setPosition(x,y);
	addStars(label);
}
void CCLevelButton::addStars(string cleanLevel)
{
	int starsQuantity=CCUserDefault::sharedUserDefault()->getFloatForKey(_levelTitle.c_str(),0);
	if(starsQuantity>0)
	{
		for(int i=0;i<starsQuantity;i++)
		{
			star[i]=new Entity(CommonKeys::keyToString(CommonKeys::IMG_ITEM_STAR));
			star[i]->setPosition(45 + i*55 ,42);
			addChild(star[i]);

		}
	}
	
}
void CCLevelButton::onTriggered()
{
	CCDirector *director = CCDirector::sharedDirector();
	LevelScene* level = LevelManager::getInstance()->loadLevel(_filename);
	
	level->_nextLevel = this->_nextLevel;
	if(level)
	{
		CommonCallbacks::navigateToScene(level->getScene());
	}
}

CCLevelButton::~CCLevelButton(void)
{
}
