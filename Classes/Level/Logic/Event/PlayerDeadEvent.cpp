#include "PlayerDeadEvent.h"
#include "..\..\..\Scene\LevelScene.h"
#include "..\Track.h";

PlayerDeadEvent::PlayerDeadEvent(LevelScene* level)
{
	//Event::Event(level);
	this->_level = level;
}

void PlayerDeadEvent::update()
{
	for (int i = 0; i < _entFree.size(); i++)
	{
		_entFree[i]->update();
	}

	PlayerBall* player = _level->_gameTrack->_player;

	if(player->numberOfRunningActions()==1)
	{
		player->changeImage(CommonKeys::IMG_PLAYER_BASE);
		shutdown();

	}
}

void PlayerDeadEvent::start()
{
	float blinkDuration = 2.0f;
	int blinks = 10;
	float moveDuration = 2.0f;
	PlayerBall* player = _level->_gameTrack->_player;
	
	CCPoint moveTo = _level->_gameTrack->_entBar[0]->getLocationFor(player);

	CCFiniteTimeAction* blinkAction = CCBlink::create(blinkDuration,blinks);
	CCFiniteTimeAction* moveBackAction = CCMoveTo::create(moveDuration,moveTo);
	
	player->runAction( blinkAction );
	player->runAction( moveBackAction );

	Event::start();
}

void PlayerDeadEvent::render()
{
	//CCLog("THIS IS AN EVENT RENDERING");
}

PlayerDeadEvent::~PlayerDeadEvent(void)
{
}
