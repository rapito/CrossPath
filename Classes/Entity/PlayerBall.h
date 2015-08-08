#pragma once
#include <vector>
#include "Entity.h"

using std::map;
using std::pair;
class Bar;
class PlayerBall : public Entity
{
public:
	map<Bar*,CCPoint> _barPoints;
	PlayerBall(void);
	~PlayerBall(void);
	Bar* _onBar;
	CCParticleSystem* _emitter;

	virtual void update();
	virtual void render();
	void startMoving();
	void stopMoving(CCNode* sender);
	bool _moving;

};

