#pragma once
#include "Bar.h"
#include "..\..\Level\Logic\Event\LevelEndEvent.h"
class EndBar : public Bar
{
public:
	EndBar(void);
	~EndBar(void);
	
	virtual void onBallEnter(LevelScene* level);
	virtual std::string getClassName();
};

