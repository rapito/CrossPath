#include "Bomb.h"


Bomb::Bomb(void)
{
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_ITEM_BOMB));
	_value = -2;
	_collected = false;
	_soundEffect = CommonKeys::keyToString(CommonKeys::SND_ITEM_BOMB);
}

void Bomb::triggerAction(LevelScene* level)
{
	if(!_collected)
	{
		Item::triggerAction(level);
		changeImage(CommonKeys::IMG_ITEM_BOMB_EXPLODED);
		
	}
}


Bomb::~Bomb(void)
{
}
