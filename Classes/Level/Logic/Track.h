#pragma once

#include <vector>
#include "Timeline.h"
#include "..\..\Entity\Bar\StartBar.h"
#include "..\..\Entity\Bar\EndBar.h"
#include "..\..\Entity\Item\Item.h"
#include "..\..\Entity\PlayerBall.h"

using namespace std;

class LevelScene;	//Forward Declaration
class Track : public Entity
{
public:
	Track(LevelScene* level);
	~Track(void);

    PlayerBall * _player;
	vector<Bar*> _entBar;
	vector<Item*> _items;
	float _speed; 
	void addItem(Item* item , Bar * bar);
	void readyTrack();
	void killPlayer();
	void update(float dt);
	void moveTrack(float dt);
	void pauseGame();
	void resumeGame();
	void addToScene(LevelScene* level, int zOrder);
	void ccTouchesBegan(CCSet* touches, CCEvent* touchEvent);
	void ccTouchesMoved(CCSet* touches, CCEvent* touchEvent);
	void ccTouchesEnded(CCSet* touches, CCEvent* touchEvent);
	void draw();
private:
	vector<Item*> _itemsBackup;
	LevelScene * _level;
	CCTouch* _currentTouch;

	/**
		Determina si el Player tiene un Path 
		posible por recorrer.
	*/
	bool noRoad();	
	Bar* newRoad();	
	void readyPositions();

};


