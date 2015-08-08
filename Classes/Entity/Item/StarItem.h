#pragma once
#include "Item.h"

class StarItem : public Item
{
public:
	StarItem(void);

	virtual void triggerAction(LevelScene* level);
	virtual std::string getClassName();
	~StarItem(void);
};

