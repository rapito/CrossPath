#include "Bar.h"

#include "..\..\Scene\LevelScene.h"
#include "..\..\Level\Logic\Track.h"

Bar::Bar(void)
{
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_BAR_BASE));
	resetPosition();
}

Bar::Bar(string filename)
{
	initWithFile(filename.c_str());
	resetPosition();
}
std::string Bar::getClassName()
{
	return "Bar";
}
void Bar::resetPosition()
{
	
	setAnchorPoint(ccp(0,0));
	setPosition(0,0);
	_ballInside = 0;
}

void Bar::onBallEnter(LevelScene* level)
{
	_ballInside = level->_gameTrack->_player;
	_ballInside->_onBar=this;
}

void Bar::onBallLeave()
{
	_ballInside->_onBar = 0;
	_ballInside = 0;
	CommonCallbacks::playSound(CommonKeys::SND_BALL_MOVE);
}

void Bar::update()
{
	if(_ballInside && !collidesWith(_ballInside))
	{
		onBallLeave();
	}
}

void Bar::render()
{

}

CCPoint Bar::getLocationFor(Entity* ent)
{
	float ballHalf = ent->getAnchorPoint().x * ((float) ent->getRect()->getMaxY());
	float width = getRect()->getMaxX() - getRect()->getMinX();
	float height = getRect()->getMaxY() - getRect()->getMinY();

	float x = this->getRect()->getMinX() + width/2.f;
	float y = ( ballHalf + getRect()->getMinY()) + 
		( rand() % (int) ( height-ballHalf*2 ) );
	return ccp(x,y);
}

Bar::~Bar(void)
{
}
