#include "Event.h"

Event::Event(void)
{
	_level = 0;
	_started = false;
	_finished = false;
	_paused = false;
}

Event::Event(LevelScene* level)
{
	_level = level;
	_started = false;
	_finished = false;
	_paused = false;
}

void Event::update()
{
	
}

void Event::updateEvent()
{
	if(_started && !_paused)
	{
		update();
	}
	else if(_finished)
	{
		shutdown();
	}
}

void Event::render()
{

}

void Event::start()
{
	startOrResume();
}

void Event::resume()
{
	startOrResume();
}

void Event::startOrResume()
{
	_started = true;
	_paused = false;
	_pausedTime = 0;

}


void Event::pause()
{
	_paused = true;
	_pausedTime = 0;//s3eTimerGetMs();
}

void Event::shutdown()
{
	_started = false;
	_finished = true;
	if(_level)
	{
		_level->_eventsVector.pop_back();
	}
}

Event::~Event(void)
{
}
