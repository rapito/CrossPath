#include "GameScene.h"


GameScene::GameScene(void)
{
	setTouchEnabled(true);

}


GameScene::~GameScene(void)
{
}

bool GameScene::init()
{
	return false;
}


CCScene* GameScene::getScene()
{
	return 0;
}
void GameScene::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent){}
void GameScene::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent){}
void GameScene::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent){}