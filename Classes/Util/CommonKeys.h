#pragma once
#include <string>

using namespace std;
class Entity;
class LevelScene;
class PlayerBall;
class Event;
class Background;
class Bar;
class Item;
class CommonKeys
{

public:
	static bool		_CFG_SOUND;
	static int		_CFG_SCN_TRANS;
	static string	_CFG_CPL_ROOT;
	static float	_CFG_SCN_TRANS_TIME;
	static int		_CONST_MAX_BAR_PER_SCREEN;

	enum TRANSITION:int
	{
		TRANS_XFADE = 111,
		TRANS_FADE,
		TRANS_FLIP,
		TRANS_PAGE_TURN,
		TRANS_SHRINK,
		TRANS_PROGRESS,
		TRANS_ZOOM

	};


	enum IMAGE:int
	{
		IMG_MENU_BG = 222,
		IMG_DUMMY,
		IMG_LVLSELECT_BG,
		IMG_OPTIONS_BG,
		IMG_LVL1_BG,
		IMG_LVL2_BG,
		IMG_LVL3_BG,
		IMG_LVL4_BG,
		IMG_LVL5_BG,
		IMG_TRACK_BG,
		IMG_ITEM_STAR,
		IMG_ITEM_BOMB,
		IMG_ITEM_BOMB_EXPLODED,
		IMG_BAR_BASE,
		IMG_BAR_BLOCK,
		IMG_BAR_BLOCK_BLOCK,
		IMG_BAR_START,
		IMG_BAR_END,
		IMG_PLAYER_BASE,
		IMG_PLAYER_BASE_MOVING,
		IMG_PLAYER_BASE_DEAD,
		IMG_BTN_BASE,
		IMG_BTN_PAUSE,
		IMG_BTN_LEVEL,
		IMG_MODAL_EMPTY,
		IMG_PLAYER_LIFE,
		IMG_GAME_TITLE,
		IMG_FX_FIRE

	};
	enum SOUND:int
	{
		SND_MENU_BG = 333,
		SND_LVLSELECT_BG,
		SND_OPTIONS_BG,
		SND_LVL1_BG,
		SND_LVL2_BG,
		SND_LVL3_BG,
		SND_LVL4_BG,
		SND_LVL5_BG,
		SND_ITEM_STAR,
		SND_ITEM_BONUS,
		SND_ITEM_BOMB,
		SND_BALL_DEAD,
		SND_BALL_MOVE,
		SND_GAME_OVER,
		SND_GAME_WON,
		SND_BTN_CLICK

	};

	enum SCENE:int
	{
		SCN_GAMESTART = 444,
		SCN_LVLSELECT,
		SCN_OPTIONS,
		SCN_LVL
	};

	enum CPLC_TYPE:int
	{
		CPL_PLAYER = 555,
		CPL_EVENT,
		CPL_BACKGROUND,
		CPL_BAR,
		CPL_ITEM
	};

	static char * keyToString(SOUND soundKey);
	static char * keyToString(IMAGE imgKey);
	
	static Entity* stringToEntity(CPLC_TYPE type, string str, LevelScene* level);
	static PlayerBall* setPlayerType(Entity* ent,string str);
	static Event* setEventType(Entity* ent,string str, LevelScene* level);
	static Background* setBackgroundType(Entity* ent,string str);
	static Bar* setBarType(Entity* ent,string str,LevelScene* level);
	static Item* setItemType(Entity* ent,string str);
};



