#pragma once
#include "Track.h"
#include "Entity/Bar/Bar.h"
//#include <../cocos2dx/draw_nodes/CCDrawingPrimitives.h>
class Track;
class Timeline
{
public:
	static Timeline* getInstance();
	static Timeline* _instance;
	static void update(Track* track);
	static void render(Track* track);
	
private:
	//Track * _track;
	Timeline(void);
};

