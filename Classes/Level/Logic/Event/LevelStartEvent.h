#pragma once
#include "..\Event.h"

class LevelStartEvent : public Event
{
public:
	LevelStartEvent(LevelScene* level);
	~LevelStartEvent(void);
	
	virtual void start();
	virtual void render();
	virtual void update();

	virtual string getClassName();
};

