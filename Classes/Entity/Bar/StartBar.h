#pragma once
#include "Bar.h"
class StartBar : public Bar
{
public:
	StartBar(void);
	~StartBar(void);
	virtual std::string getClassName();
	virtual void onBallEnter(LevelScene* level);
	virtual void onBallLeave();
};

