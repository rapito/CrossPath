#include "LevelEndEvent.h"
#include "..\..\..\UI\ModalManager.h"

LevelEndEvent::LevelEndEvent(LevelScene* level)
{
	//Event::Event(level);
	this->_level = level;
}

void LevelEndEvent::update()
{
	for (int i = 0; i < _entSlaved.size(); i++)
	{
		float scale = _entSlaved[i]->getScale();
		if(scale>=5)
		{
			_entSlaved[i]->setVisible(false);
			_level->removeChild(_entSlaved[i]);
			_entSlaved.pop_back();
			_level->_gamePaused = true;
			ModalManager::getInstance()->showWinModal(_level);
			shutdown();
		}

	}
}

void LevelEndEvent::start()
{
	CCLabelTTF* but = CCLabelTTF::create("Game Finished", "Arial", 24);
	but->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2.f,
					CCDirector::sharedDirector()->getWinSize().height/2.f));
	_level->addChild(but,5);
	but->runAction( CCScaleTo::create(2.0f,5) );
	_entSlaved.push_back(but);
	Event::start();
	int finalScore=0;

	for(int i =0; i< _level->_gameTrack->_items.size();i++)
	{
		if(_level->_gameTrack->_items[i]->getClassName()=="StarItem")
			finalScore+=_level->_gameTrack->_items[i]->_value;
	}

	int earnedStars=0;

	if(_level->_scoreGained<finalScore/3.f)
	{
		earnedStars=1;
	}
	else if(_level->_scoreGained>=finalScore/3.f  &&  _level->_scoreGained<(finalScore*2)/3.f)
	{
		earnedStars=2;
	}
	else
	{
		earnedStars=3;
	}

	string temp=_level->_title->getString();
	temp.replace(temp.find(" "),1,"_");

	if(earnedStars>CCUserDefault::sharedUserDefault()->getIntegerForKey(temp.c_str(),0))
	{
		CCUserDefault::sharedUserDefault()->setIntegerForKey(temp.c_str(),earnedStars);
	}	
	CommonCallbacks::playSound(CommonKeys::SND_GAME_WON);
}

void LevelEndEvent::render()
{
	//CCLog("THIS IS AN EVENT RENDERING");
}

LevelEndEvent::~LevelEndEvent(void)
{
}

string LevelEndEvent::getClassName()
{
	return "LevelEndEvent";
}