#include "BlockBar.h"
#include <cmath>
#include <ctime>
#include "..\..\Scene\LevelScene.h"

BlockBar::BlockBar(void)
{
	Bar::Bar(CommonKeys::keyToString(CommonKeys::IMG_BAR_BLOCK));
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_BAR_BLOCK));
	resetPosition();

	_blockDuration = 5.0f;

	int blocks = 1+rand() % 5;
	int maxHeight = getHeight()/blocks - getHeight()/3.f;
	for (int i = 0; i < blocks; i++)
	{
		Entity* block = new Entity(CommonKeys::keyToString(CommonKeys::IMG_BAR_BLOCK_BLOCK));
		CCPoint moveTo;
		
		
		addChild(block,getZOrder()+1);
		block->setPosition(getLocationFor(block));
		moveTo = ccp( block->getPositionX(), -block->getHeight()-getHeight()+block->getPositionY() );
		startBlockMovement(block,moveTo,true);
		_blocks.push_back(block);

	}
}

void BlockBar::startBlockMovement(Entity* block, CCPoint pos,bool stopActions)
{
	if(stopActions)
	{
		block->setPositionY( getHeight() - block->getHeight() );
		block->stopAllActions();
	}
	block->runAction( CCMoveTo::create(_blockDuration,pos));
}

void BlockBar::update()
{
	for (int i = 0; i < _blocks.size(); i++)
	{
		Entity* block = _blocks[i];
		
		if(_ballInside)
		{
			CCPoint point = ccp(block->getPositionX()+getPositionX(),block->getPositionY()); 
			if(_ballInside->collidesWith(&point))
			{
				CommonCallbacks::playSound(CommonKeys::SND_BALL_DEAD);
				_level->killPlayer();
				onBallLeave();
			}
		}

		CCPoint moveTo = ccp( block->getPositionX(), -block->getHeight()-getHeight()+block->getPositionY() );
		if(block->numberOfRunningActions()==0)
		{
			if(block->getPositionY()<0)
			{
				startBlockMovement(block, moveTo, true);
			}
		}
		else
		{
			if(block->getPositionY()<0)
			{
				startBlockMovement(block, moveTo,true );
			}
		}

	}
}

void BlockBar::onBallEnter(LevelScene* level)
{
	Bar::onBallEnter(level);
}

void BlockBar::onBallLeave()
{
	Bar::onBallLeave();
}



std::string BlockBar::getClassName()
{
	return "BlockBar";
}


BlockBar::~BlockBar(void)
{
}
