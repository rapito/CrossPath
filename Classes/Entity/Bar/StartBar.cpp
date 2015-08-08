#include "StartBar.h"
#include <cmath>
#include <ctime>

StartBar::StartBar(void)
{
	Bar::Bar();
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_BAR_START));
	resetPosition();
}

std::string StartBar::getClassName()
{
	return "StartBar";
}
void StartBar::onBallEnter(LevelScene* level)
{
	srand (time(NULL));
	Bar::onBallEnter(level);
	
	_ballInside->changeImage(CommonKeys::keyToString(CommonKeys::IMG_PLAYER_BASE));
	
}

void StartBar::onBallLeave()
{
	Bar::onBallLeave();
}

StartBar::~StartBar(void)
{
}
