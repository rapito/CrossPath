#include "LevelScene.h"
#include "..\UI\CCModal.h"
#include "..\UI\ModalManager.h" 
#include "..\Level\Logic\Track.h"
#include "..\Level\Logic\Event\PlayerDeadEvent.h"
#include "..\Level\Logic\Event\LevelStartEvent.h"
#include "..\Level\Logic\Event\GameOverEvent.h"

void LevelScene::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	_touch = (CCTouch*)touches->anyObject();
	CCButton *touchedBut = 0;

	if(!_gamePaused)
	{
		if(_btnPause.collidesWith(&_touch->getLocation()))
		{
			touchedBut = &_btnPause;
		}

		if(!eventsRunning())
		{
			if(touchedBut)
			{
				touchedBut->onTriggered();
			}
			_gameTrack->ccTouchesBegan(touches,touchEvent);
		}
		
	}
	else
	{
		if(_currentModal)
		{
			_currentModal->ccTouchesBegan(touches,touchEvent);
		}
	}

}
void LevelScene::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent)
{
	if(!eventsRunning())
	{
		_gameTrack->ccTouchesMoved(touches,touchEvent);
	}
}
void LevelScene::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent)
{
	if(!eventsRunning())
	{
		_gameTrack->ccTouchesEnded(touches,touchEvent);
	}
}

LevelScene::LevelScene(string title, string background, string music)
{
	_title =  CCLabelTTF::create(title.c_str(), "Arial", 42);
	_background = new Background(background,music);
	_btnPause = CCButton("",CommonKeys::IMG_BTN_PAUSE);
	_scene = 0;
	_playerLives = 3;
	_gamePaused = false;
	_playerLife=new PlayerLife(_playerLives);
	_nextLevel = "";
}

bool LevelScene::eventsRunning()
{
	return _eventsVector.size()>0;
}
void LevelScene::updateLevel(float dt)
{
	if(_gamePaused)
	{
		return;
	}
	else
	{
		if(eventsRunning())
		{
			Event* evt = _eventsVector[0];
			if(!evt->_started && !evt->_paused)
			{
				evt->start();
			}
			evt->update();
		}
		else
		{

			_gameTrack->update(dt);
		}
	}
	
}

void LevelScene::killPlayer()

{
	_gameTrack->_player->stopAllActions();
	if(--_playerLives)
	{
		_gameTrack->killPlayer();
		_eventsVector.push_back(new PlayerDeadEvent(this));
		_scoreGained = 0;
		
	}
	else
	{
		_eventsVector.push_back(new GameOverEvent(this));
	}
	_playerLife->setNewLife(&_playerLives);
	

}

void LevelScene::resetGame()
{
		++_playerLives;
		this->killPlayer();
}

void LevelScene::draw()
{
	GameScene::draw();
	if(eventsRunning())
	{
		Event* evt = _eventsVector[0];
		evt->render();
	}
}

CCScene* LevelScene::getScene()
{
	if(!_scene)
	{
		_scene = CCScene::create();
		_scene->addChild(this);
	}
	init();
	setTouchEnabled(true);

	addChild(_background,0);
	addChild(_title,1);
	_gameTrack->addToScene(this,2);
	_btnPause.addToScene(this,2);
	addChild(_playerLife,2);
	
	this->schedule(schedule_selector(LevelScene::updateLevel));
    return _scene;
}

bool LevelScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
	_title->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - _title->getContentSize().height));
	
	_background->startBackgroundMusic();
	_btnPause.setAnchorPoint(ccp(0,0));
	_btnPause.setPosition(0,visibleSize.height-_btnPause.getRect()->getMaxY());
	_playerLife->setPosition(visibleSize.width- (_playerLife->getWidth())/2,visibleSize.height-(_playerLife->getHeight())/2);
	//_btnPause.assignAction(CommonCallbacks::btnAtnBack,(GameScene*) this);
	_btnPause.assignAction(btnAtnPause,(GameScene*) this);

	
	

	//Particle
	

	return true;
}

void LevelScene::btnAtnPause(GameScene* scene)
{
	LevelScene* level = (LevelScene*) scene;
	level->pauseGame();
}


void LevelScene::pauseGame()
{
	// Al pausar el juego se llama a la instancia de ModalManager que se tiene como atributo
	// y ahi se setea el attributo PauseModal de esta escena. Las funciones del Modal son manejadas en el
	// ModalManager
	_gamePaused = true;
	_gameTrack->pauseGame();
	// Recuerda que debes utilizar Foward declaration para evitar referencias circulares;
	//_manager = new ModalManager((GameScene*)this); //asegurate de anadir la referencia a ModalManager antes de descomentar esta linea
	if(eventsRunning())
	{
		_eventsVector[0]->pause();
	}

	ModalManager::getInstance()->showPauseModal(this);
}

void LevelScene::resumeGame()
{
	_gamePaused = false;
	_gameTrack->resumeGame();
	if(_eventsVector.size()>0)
	{
		_eventsVector[0]->resume();
	}
}

void LevelScene::onExit()
{
	CCLayer::onExit();
    this->_background->stopBackgroundMusic();
}

LevelScene::~LevelScene(void)
{
}
