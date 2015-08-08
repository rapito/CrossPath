#include "Entity.h"
#include "..\Util\CommonKeys.h"

Entity::Entity(void)
{
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_DUMMY));
	_paused = false;
}

Entity::Entity(string filename)
{
	initWithFile(filename.c_str());
	_paused = false;
}

Entity::~Entity(void)
{
}

string Entity::getClassName(void)
{
	return "Entity";
}
void Entity::setPosition(CCPoint point)
{
	CCSprite::setPosition(point);
}

void Entity::setPosition(float x,float y)
{
	setPositionX(x);
	setPositionY(y);
}

void Entity::changeImage(CommonKeys::IMAGE imageKey)
{
	changeImage(CommonKeys::keyToString(imageKey));
}

void Entity::changeImage(string filename)
{
	setTexture(CCTextureCache::sharedTextureCache()->addImage(filename.c_str()));
}

void Entity::update(){}

void Entity::render(){}

void Entity::pause()
{
	_paused = true;
	pauseSchedulerAndActions();
	CCObject* child;
	CCARRAY_FOREACH(getChildren(),child)
	{
		Entity* castedChild = dynamic_cast<Entity*>(child);
		castedChild->pauseSchedulerAndActions();
	};

}

void Entity::resume()
{
	_paused = false;
	resumeSchedulerAndActions();
	CCObject* child;
	CCARRAY_FOREACH(getChildren(),child)
	{
		Entity* castedChild = dynamic_cast<Entity*>(child);
		castedChild->resumeSchedulerAndActions();
	};
}

bool Entity::collidesWith(Entity* other)
{
	return other->getRect()->intersectsRect(*getRect());
}

bool Entity::collidesWith(const CCPoint* point)
{
	return getRect()->containsPoint(*point);
	
}

float Entity::getWidth()
{
	CCRect r = *getRect();
	return r.getMaxX()-r.getMinX();
}

float Entity::getHeight()
{
	CCRect r = *getRect();
	return r.getMaxY()-r.getMinY();
}
CCRect* Entity::getRect()
{
	CCRect textureRect = getTextureRect();
	CCPoint position = getPosition();
	CCPoint anchor = getAnchorPoint();
	position.x = position.x - anchor.x*textureRect.getMaxX();
	position.y = position.y - anchor.y*textureRect.getMaxY();
	CCRect* rect = new CCRect(position.x  , position.y, textureRect.size.width, textureRect.size.height);
	return rect;
}