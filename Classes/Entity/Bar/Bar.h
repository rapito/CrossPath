#pragma once

#include <string>
#include "..\PlayerBall.h"
#include "..\Entity.h"
using std::string;
class Bar : public Entity
{
public:
	Bar(void);
	Bar(string filename);
	virtual std::string getClassName();
	virtual void onBallEnter(LevelScene* level);
	virtual void onBallLeave();
	virtual void update();
	virtual void render();
	CCPoint getLocationFor(Entity* ent);
	void resetPosition();
	~Bar(void);
	
	PlayerBall* _ballInside;
	LevelScene* _level;
	
};

