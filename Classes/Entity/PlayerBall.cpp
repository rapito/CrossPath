#include "PlayerBall.h"
#include "Bar\Bar.h"
#include "..\Util\CommonCallbacks.h"

PlayerBall::PlayerBall(void)
{
	
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_PLAYER_BASE));
	_onBar = 0;
	_moving = false;
	
	CCSize fxSize = CCSize(15,10);
	this->runAction(CCRepeatForever::create(CCWaves3D::create(40,fxSize,80,10)));
	
	_emitter = CCParticleMeteor::create();
	
    _emitter->retain();
	_emitter->setTexture( CCTextureCache::sharedTextureCache()->addImage(CommonKeys::keyToString(CommonKeys::IMG_FX_FIRE)) );
	_emitter->setPosition(getPosition());


}

PlayerBall::~PlayerBall(void)
{
}

void PlayerBall::update()
{
	if(_emitter)
	{
		_emitter->setPosition(getPosition());
	}
}

void PlayerBall::stopMoving(CCNode* sender)
{
	_moving = false;
	_barPoints.clear();
	changeImage(CommonKeys::IMG_PLAYER_BASE);

	CCSize fxSize = CCSize(15,10);
	this->runAction(CCRepeatForever::create(CCWaves3D::create(40,fxSize,80,10)));
	
	if(_onBar)
	{
		setPositionX(_onBar->getPositionX()+_onBar->getWidth()/2.f);
	}
}
void PlayerBall::startMoving()
{
	float duration = 0.55f;
	const int maxActions = 10;
	CCFiniteTimeAction *actions[maxActions];
	for(int i=0;i<maxActions;i++) actions[i] = NULL;
	int aIndex = 0;

	CCFiniteTimeAction* travelAction,*movement;

	travelAction = CCRotateTo::create(0.1f,1);
	for(map<Bar*,CCPoint>::iterator it = _barPoints.begin(); it != _barPoints.end(); it++)
	{
		if(it!=_barPoints.begin()) 
		{
			movement = CCMoveTo::create( duration, it->second);
			travelAction = CCSequence::createWithTwoActions(travelAction,movement);
		}
	}
	movement = CCCallFuncN::create( this, callfuncN_selector(PlayerBall::stopMoving));
	
	travelAction = CCSequence::createWithTwoActions(travelAction,movement);

	stopAllActions();
	this->runAction(travelAction);
	
	CommonCallbacks::playSound(CommonKeys::SND_BALL_MOVE);

	changeImage(CommonKeys::IMG_PLAYER_BASE_MOVING);
	_moving = true;
}

void PlayerBall::render()
{
}


