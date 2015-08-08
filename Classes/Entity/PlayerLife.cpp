#include "PlayerLife.h"


PlayerLife::PlayerLife(void)
{
}
PlayerLife::PlayerLife(int remainingLives)
{
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_PLAYER_LIFE));
	_remainingLives=remainingLives;
	_remainingLivesLabel=CCLabelTTF::create(  to_string(_remainingLives).c_str(), "Arial", 45);
	_remainingLivesLabel->setColor(ccc3(0,0,0));
	_remainingLivesLabel->setPosition(ccp(getWidth() - getWidth()*3/12, getHeight()-getHeight()*2/5));
	addChild(_remainingLivesLabel);
}
void PlayerLife::setNewLife(int * life)
{
	_remainingLives=*life;
	_remainingLivesLabel->setString(to_string(_remainingLives).c_str());
}
void PlayerLife::update()
{

}
void PlayerLife::render()
{

}

PlayerLife::~PlayerLife(void)
{
}
