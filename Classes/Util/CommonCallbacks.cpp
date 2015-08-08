#include "CommonCallbacks.h"

CCScene* CommonCallbacks::applySceneTransition(CCScene* scene)
{
	CCScene* toReturn = 0;
	switch (CommonKeys::_CFG_SCN_TRANS)
	{
	case CommonKeys::TRANS_XFADE:
		toReturn = CCTransitionCrossFade::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	case CommonKeys::TRANS_FADE:
		toReturn = CCTransitionFade::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	case CommonKeys::TRANS_FLIP:
		toReturn = CCTransitionFlipAngular::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	case CommonKeys::TRANS_PAGE_TURN:
		toReturn = CCTransitionPageTurn::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene,false);
		break;
	case CommonKeys::TRANS_SHRINK:
		toReturn = CCTransitionShrinkGrow::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	case CommonKeys::TRANS_PROGRESS:
		toReturn = CCTransitionProgress::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	case CommonKeys::TRANS_ZOOM:
		toReturn = CCTransitionZoomFlipAngular::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	default:
		toReturn = CCTransitionRotoZoom::create(CommonKeys::_CFG_SCN_TRANS_TIME,scene);
		break;
	}
	
	return toReturn;
}

void CommonCallbacks::navigateToScene(CommonKeys::SCENE sceneKey, GameScene* sender)
{
	CCScene* toPush;
	GameScene * gameScene;
	CCLog("Navigating To Scene: ");
	switch (sceneKey)
	{
		case CommonKeys::SCN_LVLSELECT:
			
			CCLog("Level Select");
			gameScene = new LevelSelectScene(sender);
			toPush = applySceneTransition(gameScene->getScene());
			CCDirector::sharedDirector()->pushScene(toPush);
			
			break;
		case CommonKeys::SCN_OPTIONS:
			
			CCLog("Options");
			gameScene = new OptionsScene(sender);
			toPush = applySceneTransition(gameScene->getScene());
			CCDirector::sharedDirector()->pushScene(toPush);
			
			break;
		default:
			break;
	}
}

void CommonCallbacks::navigateToScene(CCScene *to)
{
	to = applySceneTransition(to);
	CCDirector::sharedDirector()->replaceScene(to);
}

void CommonCallbacks::navigateBackToScene(GameScene* sender)
{
	// Actualmente Todas las escenas navegan hacia el menu... 
	// pero el pop scene no reemplaza el sonido
	 CCDirector::sharedDirector()->popScene();
}
void CommonCallbacks::btnAtnBack(GameScene * sender)
{
	navigateBackToScene(sender);
}
void CommonCallbacks::btnAtnSound(GameScene* sender)
{
	CommonKeys::_CFG_SOUND = !CommonKeys::_CFG_SOUND;
	CCUserDefault::sharedUserDefault()->setBoolForKey("Sound",CommonKeys::_CFG_SOUND);
	sender->_background->toggleBackgroundMusic();
}

void CommonCallbacks::playSound(CommonKeys::SOUND soundKey)
{
	if(CommonKeys::_CFG_SOUND)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(CommonKeys::keyToString(soundKey));
	}
}

