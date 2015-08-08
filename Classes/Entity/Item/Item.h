#pragma once
#include <string>
#include "..\PlayerBall.h"
#include "..\..\Scene\LevelScene.h"
#include "..\..\Entity\Bar\Bar.h"

using namespace std;

class Item : public Entity
{
public:
	Item(void);
	~Item(void);
	virtual void triggerAction(LevelScene* level);
	virtual void reset();
	int _value;
	bool _collected;
	string _soundEffect;
	Bar* _onBar;
};

