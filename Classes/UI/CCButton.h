#pragma once

#include <cocos2d.h>
#include "..\Entity\Entity.h"
#include "..\Scene\GameScene.h"

using std::string;
USING_NS_CC;

class CCButton : public Entity
{
public:
	CCButton(void);
	CCButton(string label, CommonKeys::IMAGE imageKey);
	CCButton(string label);
	CCButton(string label,float x,float y);
	~CCButton(void);

	void initButton(string label, string filename);
	void addToScene(GameScene* scene, char zOrder);
	void removeFromScene(GameScene* scene);
	void CCButton::release(void);
	void assignAction(void (*callBackFunction)(GameScene*),GameScene* sender);
	//void assignAction(void (*callBackFunction),GameScene* sender);
	virtual void onTriggered();
	void setLabel(string label);
	CCLabelTTF* _fullLabel; 
protected:
	string _label;
	GameScene* _sender;
	void (* _actionTriggered)(GameScene*);

};

