#pragma once
#include "cocos2d.h"
#include "..\Level\Logic\UpDrawable.h"
#include "..\Util\CommonKeys.h"

USING_NS_CC;

class Entity : public CCSprite, public UpDrawable
{
public:
	Entity(void);
	Entity(string filename);
	~Entity(void);

	void setPosition(CCPoint point);
	void setPosition(float x,float y);
	void changeImage(CommonKeys::IMAGE imageKey);
	void changeImage(string filename);

	virtual std::string getClassName();
	virtual void update();
	virtual void render();
	virtual void pause();
	virtual void resume();

	bool collidesWith(Entity* other);
	bool collidesWith(const CCPoint* point);

	CCRect* getRect();

	float getWidth();
	float getHeight();
	
	bool _paused;
};

