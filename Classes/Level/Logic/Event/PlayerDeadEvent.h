#pragma once
#include "..\Event.h"
class PlayerDeadEvent : public Event
{
public:
	PlayerDeadEvent(LevelScene* level);
	~PlayerDeadEvent(void);

	virtual void start();
	virtual void render();
	virtual void update();
};

