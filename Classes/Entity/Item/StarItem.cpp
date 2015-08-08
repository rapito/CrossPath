#include "StarItem.h"


StarItem::StarItem(void)
{
	_value = 2;
	_collected = false;
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_ITEM_STAR));
	_soundEffect = CommonKeys::keyToString(CommonKeys::SND_ITEM_STAR);
}

std::string StarItem::getClassName()
{
	return "StarItem";
}

void StarItem::triggerAction(LevelScene* level)
{
	if(!_collected)
	{
		this->setVisible(false);
	}
	Item::triggerAction(level);

}

StarItem::~StarItem(void)
{
}
