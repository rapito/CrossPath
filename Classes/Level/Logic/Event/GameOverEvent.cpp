#include "GameOverEvent.h"
#include "..\..\..\UI\ModalManager.h"
#include "..\Track.h"

GameOverEvent::GameOverEvent(LevelScene* level)
{
	//Event::Event(level);
	this->_level = level;
	_level->_gameTrack->_player->changeImage(CommonKeys::IMG_PLAYER_BASE_DEAD);
}


GameOverEvent::~GameOverEvent(void)
{
}


void GameOverEvent::update()
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
			ModalManager::getInstance()->showLoseModal(_level);
			shutdown();
		}

	}
}

void GameOverEvent::start()
{
	CCLabelTTF* but = CCLabelTTF::create("Game Over", "Arial", 24);
	but->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2.f,
					CCDirector::sharedDirector()->getWinSize().height/2.f));
	_level->addChild(but,5);
	but->runAction( CCScaleTo::create(2.0f,5) );
	_entSlaved.push_back(but);
	Event::start();
	CommonCallbacks::playSound(CommonKeys::SND_GAME_OVER);
}

void GameOverEvent::render()
{
	//CCLog("THIS IS AN EVENT RENDERING");
}

string GameOverEvent::getClassName()
{
	return "GameOverEvent";
}