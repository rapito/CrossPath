#pragma once

#include <vector>
#include "GameScene.h"
#include "..\UI\CCButton.h"
#include "..\Level\Logic\Event.h"
#include "..\Util\CommonCallbacks.h"
#include "..\UI\CCModal.h"
#include "..\Entity\PlayerLife.h"

using namespace std;

class Track;	//Forward Declaration
class LevelScene : public GameScene
{

public:
	LevelScene(string title, string background, string music);
	~LevelScene(void);

	Track *_gameTrack;
	vector<Event*> _eventsVector;
	CCModal* _currentModal;
	string _nextLevel;

	static void btnAtnPause(GameScene* sender);
	virtual CCScene* getScene();
	void updateLevel(float dt);
	
	void pauseGame();
	void resumeGame();
	void killPlayer();
	void resetGame();
	int _scoreGained;
	int _playerLives;
	bool _gamePaused;
	PlayerLife * _playerLife;
	//int _scoreLimit;

private:
	CCTouch* _touch;
	CCButton _btnPause;
	
	
	bool eventsRunning();
	virtual void draw();
	virtual bool init();
	virtual void onExit();
	virtual void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	virtual void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);
	
};
