#include "Bonus.h"


Bonus::Bonus(void)
{
	_value = 3;
	_soundEffect = CommonKeys::keyToString(CommonKeys::SND_ITEM_BONUS);
}

void Bonus::triggerAction(LevelScene* level)
{
	Item::triggerAction(level);
}


Bonus::~Bonus(void)
{
}
