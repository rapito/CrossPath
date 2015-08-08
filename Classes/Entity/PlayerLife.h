#pragma once
#include "Entity\Entity.h"
using std::string;
class PlayerLife : public Entity
{

public:
	int _remainingLives;
	CCLabelTTF * _remainingLivesLabel;
	virtual void update();
	virtual void render();
	void setNewLife(int * life);
	PlayerLife(void);
	PlayerLife(int);
	~PlayerLife(void);
};

