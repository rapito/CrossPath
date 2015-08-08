#pragma once
#include "Item.h"
class Bomb : public Item
{
public:
	Bomb(void);
	
	virtual void triggerAction(LevelScene* level);

	~Bomb(void);
};

