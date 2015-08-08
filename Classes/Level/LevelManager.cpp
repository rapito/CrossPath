#include "LevelManager.h"
#include "..\UI\CCLevelButton.h"
#include "..\Level\Logic\Track.h"

LevelManager* LevelManager::_instance;

void LevelManager::assertArchive(Document* archive)
{
	assert(archive->IsObject());
	assert((*archive)["LevelArchive"].IsObject());
	assert((*archive)["LevelArchive"]["Levels"].IsArray());
}

void LevelManager::assertLevel(Document* level)
{
	assert(level->IsObject());
	assert((*level)["Level"]["Title"].IsString());
	
	const Value& events = (*level)["Level"]["Events"];
	const Value& background = (*level)["Level"]["Background"];
	const Value& track = (*level)["Level"]["Track"];

	
	assert(events.IsArray());
	
	assert(background.IsObject());
	assert(background.HasMember("Type"));
	assert(background.HasMember("Image"));
	assert(background.HasMember("Music"));

	assert(track.IsObject());
	assert(track.HasMember("Player"));
	assert(track.HasMember("Bars"));

}

LevelScene* LevelManager::loadLevel(string filename)
{
	LevelScene* level;
	try
	{
		filename = CommonKeys::_CFG_CPL_ROOT+filename;
		rapidjson::Document doc;
		JsonParser::getDocumentFromFile(&doc,filename);
		assertLevel(&doc);
	
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		const Value& lvl = doc["Level"];
		const Value& events = lvl["Events"];
		const Value& bg = lvl["Background"];
		const Value& ball = lvl["Track"]["Player"];
		const Value& bars = lvl["Track"]["Bars"];

		//CREACION: LEVEL
		//ASIGNACION: BACKGROUND
		level = new LevelScene( lvl["Title"].GetString(),bg["Image"].GetString(),
								bg["Music"].GetString());
		//ASIGNACION: EVENTS
		for(SizeType i = 0; i < events.Size();i++)
		{
			string eventType = events[i]["Name"].GetString();
			Event* event = (Event*) CommonKeys::stringToEntity(CommonKeys::CPL_EVENT,eventType,level);
		
			level->_eventsVector.push_back(event);
		}
		//!ASIGNACION: EVENTS

		//ASIGNACION: TRACK
		Track* track = new Track(level);
		level->_gameTrack = track;
	
		//--CREACION: PLAYER	
		track->_player = (PlayerBall*) CommonKeys::stringToEntity(CommonKeys::CPL_PLAYER,ball["Type"].GetString(),level);
		

		//--CREACION: BARS
		for(SizeType i = 0; i < bars.Size();i++)
		{
			string barType = bars[i]["Type"].GetString();
			Bar* bar = (Bar*) CommonKeys::stringToEntity(CommonKeys::CPL_BAR,barType,level);
			//ASIGNACION: ITEMS
			const Value& items = bars[i]["Items"];
		
			for(SizeType j = 0; items.IsArray() && j < items.Size();j++)
			{
				string itemType = items[j]["Name"].GetString();
				Item* item = (Item*) CommonKeys::stringToEntity(CommonKeys::CPL_ITEM,itemType,level);
				track->addItem( item , bar );
			}
			//--!ASIGNACION: ITEMS
			track->_entBar.push_back(bar);
		}
		
		//!ASIGNACION: NEXT LEVEL
		if(lvl["Next"].IsString() )
		{
			level->_nextLevel = lvl["Next"].GetString();
		}
		//--!ASIGNACION: NEXT LEVEL

		//!ASIGNACION: TIEMPO
		if(lvl["Speed"].IsDouble() )
		{
			track->_speed = lvl["Speed"].GetDouble();
		}
		//--!ASIGNACION: TIEMPO


		//--!CREACION: BARS
		track->readyTrack();
		//!ASIGNACION: TRACK
	}
	catch(int x)
	{
		CCLog("ERROR LOADING LEVEL %s!!!!",filename);
	}
	return level;
}

string LevelManager::getLevelTitle(string filename)
{
		filename = CommonKeys::_CFG_CPL_ROOT+filename;
		rapidjson::Document doc;
		JsonParser::getDocumentFromFile(&doc,filename);
		assertLevel(&doc);
	
		CCSize size = CCDirector::sharedDirector()->getWinSize();
		const Value& lvl = doc["Level"];
		const Value& title = lvl["Title"];

		return title.GetString();
}
void LevelManager::initLevelsButtons(vector<CCLevelButton*>* btns, char* archive)
{
	string filename = CommonKeys::_CFG_CPL_ROOT+string(archive);
	rapidjson::Document document;
	JsonParser::getDocumentFromFile(&document,filename);
	assertArchive(&document);

	int cpr = 5;	//Columns Per Row
	
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	const Value& levels =  document["LevelArchive"]["Levels"];

	for(SizeType i = 0; i < levels.Size();i++)
	{
		string levelFile = levels[i]["File"].GetString();
		string nextLevelFile = "";

		int s = levels.Size();
		float prevX = (size.width/s)*(i);
		float y		= size.height/2.f;
		float x		= (size.width/s)*(i+1);		
		x = prevX+(x-prevX)/2.f;
		
		//Buscamos cual es el siguiente nivel.
		if(i+1<levels.Size())
		{
			nextLevelFile = levels[i+1]["File"].GetString();
		}

		btns->push_back(new CCLevelButton(levelFile,x,y,nextLevelFile,getLevelTitle(levelFile)));
	}
}

LevelManager* LevelManager::getInstance()
{
	return !_instance ? (_instance=new LevelManager()):_instance;
}

LevelManager::LevelManager(void)
{
}


LevelManager::~LevelManager(void)
{
}

