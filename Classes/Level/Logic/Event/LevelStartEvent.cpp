#include "LevelStartEvent.h"


LevelStartEvent::LevelStartEvent(LevelScene* level)
{
	//Event::Event(level);
	this->_level = level;
}

void LevelStartEvent::update()
{
	for (int i = 0; i < _entSlaved.size(); i++)
	{
		float scale = _entSlaved[i]->getScale();
		if(scale>=5)
		{
			_entSlaved[i]->setVisible(false);
			_level->removeChild(_entSlaved[i]);
			shutdown();
			_entSlaved.pop_back();
		}
	}
}

void LevelStartEvent::start()
{
	CCLabelTTF* but = CCLabelTTF::create("Game Started", "Arial", 24);
	but->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2.f,
					CCDirector::sharedDirector()->getWinSize().height/2.f));
	_level->addChild(but,5);
	but->runAction( CCScaleTo::create(2.0f,5) );
	_entSlaved.push_back(but);
	Event::start();
}

void LevelStartEvent::render()
{
	//CCLog("THIS IS AN EVENT RENDERING");
}

LevelStartEvent::~LevelStartEvent(void)
{
}

string LevelStartEvent::getClassName()
{
	return "LevelStartEvent";
}