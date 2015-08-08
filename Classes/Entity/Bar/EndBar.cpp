#include "EndBar.h"
#include "..\..\Level\Logic\Track.h"

EndBar::EndBar(void)
{
	Bar::Bar();
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_BAR_END));
	resetPosition();
}


void EndBar::onBallEnter(LevelScene* level)
{
	Bar::onBallEnter(level);
	level->_eventsVector.push_back(new LevelEndEvent(level));
}

std::string EndBar::getClassName()
{
	return "EndBar";
}


EndBar::~EndBar(void)
{
}
