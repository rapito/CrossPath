#pragma once
#include "Item.h"
class Bonus : public Item
{
public:
	Bonus(void);

	void triggerAction(LevelScene* level);
	
	~Bonus(void);
};

