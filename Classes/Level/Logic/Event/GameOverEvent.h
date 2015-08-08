#pragma once
#include "..\Event.h"
class GameOverEvent :
	public Event
{
public:
	GameOverEvent(LevelScene* level);
	~GameOverEvent(void);

	virtual void start();
	virtual void render();
	virtual void update();
	virtual string getClassName();
};

