#pragma once

#include <cocos2d.h>
#include "CommonKeys.h"
#include "..\Scene\GameScene.h"
#include "..\Scene\LevelScene.h"
#include "..\Scene\LevelSelectScene.h"
#include "..\Scene\MenuScene.h"
#include "..\Scene\OptionsScene.h"

USING_NS_CC;

class CommonCallbacks
{
public:
	static CCScene* applySceneTransition(CCScene* scene);
	static void navigateToScene(CommonKeys::SCENE sceneKey, GameScene* sender);
	static void navigateToScene(CCScene *to);
	static void navigateBackToScene(GameScene * sender);
	static void btnAtnBack(GameScene * sender);
	static void btnAtnSound(GameScene * sender);
	static void playSound(CommonKeys::SOUND soundKey);
};

