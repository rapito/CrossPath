#pragma once
#include "..\Event.h"
#include "Level/Logic/Track.h"

class LevelEndEvent : public Event
{
public:
	LevelEndEvent(LevelScene* level);
	~LevelEndEvent(void);

	virtual void start();
	virtual void render();
	virtual void update();
	virtual string getClassName();
};

