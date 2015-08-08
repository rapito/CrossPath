#pragma once
#include <vector>
#include "UpDrawable.h"
#include "..\..\Scene\LevelScene.h"
#include "..\..\Entity\Entity.h"

using namespace std;
class LevelScene;
class Event : public Entity
{
public:
	LevelScene* _level;
	Event(void);
	Event(LevelScene* _level);
	~Event(void);
	void updateEvent();
	void pause();
	void shutdown();
	virtual void start();
	virtual void render();
	virtual void update();
	virtual void resume();
	void startOrResume();


	bool _started;
	bool _paused;
	long _pausedTime;
	bool _finished;
protected:
	vector<Entity*> _entFree;
	vector<CCSprite*> _entSlaved;
};

