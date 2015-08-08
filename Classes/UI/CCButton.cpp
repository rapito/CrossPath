#include "CCButton.h"
#include "..\Util\CommonCallbacks.h"

CCButton::CCButton(void)
{
	setPosition(0,0);
}

CCButton::CCButton(string label, CommonKeys::IMAGE imageKey)
{
	initButton(label,CommonKeys::keyToString(imageKey));
}

CCButton::CCButton(string label)
{
	initButton(label,CommonKeys::keyToString(CommonKeys::IMG_BTN_BASE));	
}

CCButton::CCButton(string label,float x,float y)
{
	initButton(label,CommonKeys::keyToString(CommonKeys::IMG_BTN_BASE));	
	setPosition(x,y);
}

void CCButton::initButton(string label, string filename)
{
	this->_label = label.c_str();
	setPosition(0,0);
	initWithFile(filename.c_str());	
	this->_fullLabel = CCLabelTTF::create(_label.c_str(), "Arial", 24);;

	
	_fullLabel->setColor(ccc3(0,0,0));
	float labelX = getWidth()/2.f;//getPositionX();
	float labelY = getHeight()/2.f;//getPositionY();
	_fullLabel->setPosition(ccp(labelX,labelY));
	
}

void CCButton::setLabel(string label)
{
	this->_label= label;
}

void CCButton::addToScene(GameScene* scene, char zOrder)
{

	scene->addChild(this,zOrder);
	addChild(_fullLabel,zOrder+1);
}

void CCButton::removeFromScene(GameScene* scene)
{
	scene->removeChild(this);
	scene->removeChild(this->_fullLabel);
}

void CCButton::assignAction(void (*callBackFunction)(GameScene*),GameScene* sender)
{
	_actionTriggered = callBackFunction;
	_sender = sender;
}/*
void CCButton::assignAction(void (*callBackFunction),GameScene* sender)
{
	_actionTriggered = callBackFunction;
	_sender = sender;
}*/
void CCButton::onTriggered()
{
	CommonCallbacks::playSound(CommonKeys::SND_BTN_CLICK);
	_actionTriggered(_sender);
}

CCButton::~CCButton(void)
{

}

