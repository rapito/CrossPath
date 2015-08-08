#include "Item.h"


Item::Item(void)
{

	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_DUMMY));
	_value = 1;
}

Item::~Item(void)
{
}

void Item::reset()
{
	_collected = false;
	setVisible(true);
}


void Item::triggerAction(LevelScene* level)
{
	if(!_collected)
	{
		_collected = true;
		level->_scoreGained+= _value;
		
		if(CommonKeys::_CFG_SOUND)
		{
			CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(_soundEffect.c_str());
		}
	}
}