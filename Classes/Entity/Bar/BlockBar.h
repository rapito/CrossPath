#pragma once
#include <vector>
#include "Bar.h"
using std::string;
using std::vector;
class BlockBar : public Bar
{
public:
	float _blockDuration;
	vector<Entity* > _blocks;
	string getClassName();
	BlockBar(void);
	~BlockBar(void);
	
	virtual void onBallEnter(LevelScene* level);
	virtual void onBallLeave();
	virtual void update();
private: 
	void startBlockMovement(Entity* block, CCPoint pos,bool stopActions);
};

