#include "Track.h"
#include "..\..\Scene\LevelScene.h"

Track::Track(LevelScene* level)
{
	initWithFile(CommonKeys::keyToString(CommonKeys::IMG_TRACK_BG));
	_level = level;
	_player = new PlayerBall();

	_currentTouch = 0;
	setAnchorPoint(ccp(0,0));
	setPosition(0,0);
	_speed= -1;
}

void Track::addItem(Item* item, Bar* bar)
{
	item->_onBar = bar;
	_items.push_back(item);
}

void Track::readyPositions()
{
	int maxBarsPerScreen = CommonKeys::_CONST_MAX_BAR_PER_SCREEN;
	int barsSize = _entBar.size()>maxBarsPerScreen?maxBarsPerScreen:_entBar.size();

	float barMargins = CCDirector::sharedDirector()->getWinSize().width / barsSize;

	for(int b=0;b<(int)_entBar.size();b++)
	{
		Bar* bar = _entBar[b];
		bar->setPosition((barMargins/2.f)+(b*barMargins),0);
	}

	for(int b=0;b<(int)_items.size();b++)
	{
		Item* item= _items[b];
		if(item->_onBar)
		{
			item->setPosition((CCPoint)item->_onBar->getLocationFor(item) );
		}
	}
}

void Track::readyTrack()
{
	readyPositions();

	_entBar[0]->onBallEnter(_level);
	_player->setPosition( (CCPoint) _entBar[0]->getLocationFor(_player) );
	

}

void Track::pauseGame()
{
	_player->pause();

	for (int i = 0; i < _entBar.size(); i++)
	{
		_entBar[i]->pause();
	}
	
	for (int i = 0; i < _items.size() ; i++)
	{
		_items[i]->pause();
	}
}

void Track::resumeGame()
{
	_player->resume();

	for (int i = 0; i < _entBar.size(); i++)
	{
		_entBar[i]->resume();
	}
	
	for (int i = 0; i < _items.size() ; i++)
	{
		_items[i]->resume();
	}
}

void Track::killPlayer()
{
	_player->stopMoving(this);
	_player->changeImage(CommonKeys::IMG_PLAYER_BASE_DEAD);

	int maxBarsPerScreen = CommonKeys::_CONST_MAX_BAR_PER_SCREEN;
	int barsSize = _entBar.size()>maxBarsPerScreen?maxBarsPerScreen:_entBar.size();
	float barMargins = CCDirector::sharedDirector()->getWinSize().width / barsSize;

	readyPositions();
	for (int i = 0; i < _items.size(); i++)
	{
		_items[i]->reset();
	}
	
}

void Track::moveTrack(float dt)
{
	if(_speed<=0) return;
	
	Bar* lastBar = _entBar[_entBar.size()-1 ];
	int lastBarXPosition = CCDirector::sharedDirector()->getWinSize().width - 
		lastBar->getWidth() - (CCDirector::sharedDirector()->getWinSize().width/CommonKeys::_CONST_MAX_BAR_PER_SCREEN);
	
	for(int c=0;c<(int)_items.size();++c)
	{
		Item* item = _items[c];
		if(lastBar->getPositionX()>lastBarXPosition)
		{
			item->setPositionX(item->getPositionX()-(_speed*dt));
		}
	}

	for (int i = 0; i < _entBar.size(); i++)
	{
		Bar* bar = _entBar[i];
		if(lastBar->getPositionX()>lastBarXPosition)
		{
			bar->setPositionX(bar->getPositionX()-(_speed*dt));
		}
	}
	
	if(lastBar->getPositionX()>lastBarXPosition)
	{
		_player->setPositionX(_player->getPositionX()-(_speed*dt));
		for (map<Bar*,CCPoint>::iterator i = _player->_barPoints.begin(); i != _player->_barPoints.end(); i++)
		{
			CCPoint* point = &i->second;
			
			point->setPoint(point->x-(_speed*dt),point->y);
		}
	}

}

void Track::update(float dt)
{
	_player->update();
	
	for(int c=0;c<(int)_items.size();++c)
	{
		Item* item = _items[c];
		if(item->collidesWith(_player))
		{
			item->triggerAction(_level);
		}
	}

	for (int i = 0; i < _entBar.size(); i++)
	{
		Bar* bar = _entBar[i];
		bar->update();
		if(bar->collidesWith(_player) && !bar->_ballInside)
		{
			bar->onBallEnter(_level);
		}
	}
	moveTrack(dt);

	if(_player->getPositionX()+_player->getWidth()/2.f<0)
	{
		_level->killPlayer();
	}
}



void Track::ccTouchesBegan(CCSet* touches, CCEvent* touchEvent)
{
	if(!_level->_gamePaused)
	{
		CCTouch * touch = (CCTouch*)touches->anyObject();
		if(_player->collidesWith(&touch->getLocation()))
		{
			_player->_barPoints.insert(pair<Bar*,CCPoint>((Bar*)NULL,touch->getLocation()));
		}
		//cc_timeval timeval;
		//int = CCTime::gettimeofdayCocos2d(
	}
	
	
}
void Track::ccTouchesMoved(CCSet* touches, CCEvent* touchEvent)
{
	
	if(!_level->_gamePaused)
	{
		_currentTouch = (CCTouch*)touches->anyObject();

		//AntiTrampa
		if(_currentTouch->getLocation().y>getTextureRect().getMaxY())
		{
			_player->_barPoints.clear();
			return;
		}

		Bar* bar;
		if(bar = newRoad())
		{
			CCPoint point = ccp(bar->getPositionX()+bar->getWidth()/2.f,
								_currentTouch->getLocation().y);
			_player->_barPoints.insert(pair<Bar*,CCPoint>(bar,point));
		}
	}
}
void Track::ccTouchesEnded(CCSet* touches, CCEvent* touchEvent)
{
	
	if(!_level->_gamePaused)
	{
		if(noRoad() && !_player->_moving)
		{
			_player->_barPoints.clear();
		}
		else if(!noRoad())
		{
			_player->startMoving();
		}

		_currentTouch = 0;
	}
}

Bar* Track::newRoad()
{
	
	if(_player->_moving || _player->_barPoints.size()<=0 || (_currentTouch && _currentTouch->getLocation().x < _player->getPositionX()))
	{
		return NULL;
	}

	for(int i=_entBar.size()-1 ; i>0 ; i-- )
	{
		if( _entBar[i]->collidesWith(&_currentTouch->getLocation())) 
		{
			if(_entBar[i]!=_player->_onBar)
			{
				map<Bar*,CCPoint>::iterator it = _player->_barPoints.find(_entBar[i]);
				if(it == _player->_barPoints.end())
				{
					return _entBar[i];
				}
			}
		}
	}
	return NULL;
}
bool Track::noRoad()
{
	return _player->_barPoints.size()<1;
}


void Track::addToScene(LevelScene* level, int zOrder)
{
	level->addChild(this,zOrder++);
	for(int b=0;b<(int)_entBar.size();b++)
	{
		Bar* bar = _entBar[b];
		level->addChild(bar,zOrder);
	}
	zOrder++;
	for(int b=0;b<(int)_items.size();b++)
	{
		Item* item= _items[b];
		level->addChild(item,zOrder);
	}
	
	level->addChild(_player->_emitter,++zOrder);
	level->addChild(_player,++zOrder);
	
}

void Track::draw()
{
	Entity::draw();
    Timeline::getInstance()->render(this);
	if(_currentTouch)
	{
		map<Bar*,CCPoint> points = _player->_barPoints;
		
		int i=0;
		glLineWidth(20);
		for(map<Bar*,CCPoint>::iterator it=points.begin(); i+1<points.size();i++)
		{
			CCPoint from = it->second;
			CCPoint to = (++it)->second;

			ccDrawLine(from,to);
		}

		if(points.size()>0)
		{
			ccDrawLine((--points.end())->second,_currentTouch->getLocation());
		}
	}
}

Track::~Track(void)
{
}
