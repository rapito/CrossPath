#include "CCModal.h"
#include "../Scene/LevelScene.h"


CCModal::CCModal(string title,vector<CCButton*> btnVector)
{
	assert(btnVector.size()>0);

	_btnVector = btnVector;
	_title = CCLabelTTF::create(title.c_str(), "Arial", 32);
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_MODAL_EMPTY));
	setAnchorPoint(ccp(0.5f,0.5f));
	setupPositions();
}

void CCModal::setupPositions()
{
	CCRect rect = getTextureRect();
	CCSize size = CCDirector::sharedDirector()->getWinSize();
		
	setPosition( ccp(size.width/2,size.height/2) );
		
	size = CCSize(rect.getMaxX()-rect.getMinX(),
	  			  rect.getMaxY()-rect.getMinY());

	for (int i = _btnVector.size()-1; i >= 0; i--)
	{
		int s = _btnVector.size();
		float prevY = (0.667f*size.height/s)*(i);
		float x		= size.width/2.f;
		float y		= size.height/3+ (0.667f*size.height/s)*(i+1);		
		y = prevY+(y-prevY)/2.f;
		_btnVector[i]->setPosition(ccp(x,y));

	}
	//Last Button positioned
	CCButton* but = _btnVector[_btnVector.size()-1];
	_title->setPosition(ccp(but->getPositionX(),
		but->getPositionY()+but->getHeight()+_title->getTextureRect().getMaxY()/2.f));
}

void CCModal::addToScene(LevelScene* level)
{
	int zOrder = 10;
	level->addChild(this,zOrder++);
	for (int i = 0; i < _btnVector.size(); i++)
	{
		CCButton* but = _btnVector[i];
		addChild(but,zOrder);
		but->addChild(but->_fullLabel,zOrder+1);   
		
	}
	addChild(_title,zOrder);
	level->_currentModal = this;
}

void CCModal::cleanButtonsUp(LevelScene* level)
{
	for(int c = 0;c<this->_btnVector.size();++c)
	{
		_btnVector[c]->removeFromScene(level);
	}
}

void CCModal::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	CCTouch* touch = (CCTouch*)touches->anyObject();
	CCPoint location = touch->getLocation();
	CCButton *but = _btnVector[0];
	location.x -= but->getWidth();
	location.y -= but->getHeight();

	for(int c = 0;c<_btnVector.size();++c)
	{
		if(_btnVector[c]->collidesWith(&location))
		{
			_btnVector[c]->onTriggered();
			return;
		}
	}
}

CCModal::~CCModal(void)
{
}
