#include "CommonKeys.h"
#include "..\Entity\PlayerBall.h";
#include "..\Level\Logic\Event\LevelStartEvent.h"
#include "..\Level\Logic\Event\LevelEndEvent.h"
#include "..\Entity\Item\StarItem.h";
#include "..\Entity\Item\Bomb.h";
#include "..\Scene\LevelScene.h";
#include "..\Entity\Bar\StartBar.h";
#include "..\Entity\Bar\EndBar.h";
#include "..\Entity\Bar\BlockBar.h";

bool	CommonKeys::_CFG_SOUND			= true;
int		CommonKeys::_CFG_SCN_TRANS		= CommonKeys::TRANS_PAGE_TURN;
string	CommonKeys::_CFG_CPL_ROOT		= "Configuration Files/";
float	CommonKeys::_CFG_SCN_TRANS_TIME = 1.0f;
int		CommonKeys::_CONST_MAX_BAR_PER_SCREEN = 7;

char* CommonKeys::keyToString(SOUND soundKey)
{
	char * result;
	switch (soundKey)
	{
		case CommonKeys::SND_MENU_BG:
			result = "BG_MENU.mp3";
			break;
		case CommonKeys::SND_LVLSELECT_BG:
			result = "BG_LVLSELECT.mp3";
			break;
		case CommonKeys::SND_OPTIONS_BG:
			result = "BG_OPTIONS.mp3";
			break;
		case CommonKeys::SND_LVL1_BG:
			result = "BG_LEVEL1.mp3";
			break;
		case CommonKeys::SND_LVL2_BG:
			result = "BG_LEVEL2.mp3";
			break;
		case CommonKeys::SND_LVL3_BG:
			result = "BG_LEVEL3.mp3";
			break;
		case CommonKeys::SND_LVL4_BG:
			result = "BG_LEVEL4.mp3";
			break;
		case CommonKeys::SND_LVL5_BG:
			result = "BG_LEVEL5.mp3";
			break;
		case CommonKeys::SND_ITEM_STAR:
			result = "ITEM_GET_STAR.wav";
			break;
		case CommonKeys::SND_ITEM_BONUS:
			result = "ITEM_GET_STAR.wav";
			break;
		case CommonKeys::SND_ITEM_BOMB:
			result = "ITEM_BOMB.wav";
			break;
		case CommonKeys::SND_BALL_DEAD:
			result = "BALL_DEAD.wav";
			break;
		case CommonKeys::SND_BALL_MOVE:
			result = "BALL_MOVE.wav";
			break;
		case CommonKeys::SND_GAME_OVER:
			result = "LVL_GAMEOVER.wav";
			break;
		case CommonKeys::SND_GAME_WON:
			result = "LVL_GAMEWON.wav";
			break;
		case CommonKeys::SND_BTN_CLICK:
			result = "BTN_CLICK.wav";
			break;

		default:
			break;
	}
	return result;
}

char* CommonKeys::keyToString(IMAGE imgKey)
{
	char * result;
	switch (imgKey)
	{
		case CommonKeys::IMG_MENU_BG:
			result = "BG_MENU.png";
			break;
		case CommonKeys::IMG_DUMMY:
			result = "CloseSelected.png";
			break;
		case CommonKeys::IMG_LVLSELECT_BG:
			result = "BG_LVLSELECT.png";
			break;
		case CommonKeys::IMG_TRACK_BG:
			result = "BG_TRACK.png";
			break;
		case CommonKeys::IMG_OPTIONS_BG:
			result = "BG_OPTIONS.png";
			break;
		case CommonKeys::IMG_LVL1_BG:
			result = "BG_LEVEL1.png";
			break;
		case CommonKeys::IMG_LVL2_BG:
			result = "BG_LEVEL2.png";
			break;
		case CommonKeys::IMG_LVL3_BG:
			result = "BG_LEVEL3.png";
			break;
		case CommonKeys::IMG_LVL4_BG:
			result = "BG_LEVEL4.png";
			break;
		case CommonKeys::IMG_LVL5_BG:
			result = "BG_LEVEL5.png";
			break;
		case CommonKeys::IMG_ITEM_STAR:
			result = "ITEM_STAR.png";
			break;
		case CommonKeys::IMG_ITEM_BOMB:
			result = "ITEM_BOMB.png";
			break;
		case CommonKeys::IMG_ITEM_BOMB_EXPLODED:
			result = "ITEM_BOMB_EXPLOTION.png";
			break;
		case CommonKeys::IMG_BAR_BASE:
			result = "BAR_BASE.png";
			break;
		case CommonKeys::IMG_BAR_BLOCK:
			result = "BAR_BLOCK.png";
			break;
		case CommonKeys::IMG_BAR_BLOCK_BLOCK:
			result = "BAR_BLOCK_BLOCK.png";
			break;
		case CommonKeys::IMG_BAR_START:
			result = "BAR_START.png";
			break;
		case CommonKeys::IMG_BAR_END:
			result = "BAR_END.png";
			break;
		case CommonKeys::IMG_PLAYER_BASE:
			result = "BALL_STOP.png";
			break;
		case CommonKeys::IMG_PLAYER_BASE_MOVING:
			result = "BALL_MOVING.png";
			break;
		case CommonKeys::IMG_PLAYER_BASE_DEAD:
			result = "BALL_DEAD.png";
			break;
		case CommonKeys::IMG_BTN_BASE:
			result = "BTN_BASE.png";
			break;
		case CommonKeys::IMG_BTN_PAUSE:
			result = "BTN_PAUSE_P.png";
			break;
		case CommonKeys::IMG_BTN_LEVEL:
			result = "BTN_LEVEL.png";
			break;
		case CommonKeys::IMG_MODAL_EMPTY:
			result = "MODAL_EMPTY.png";
			break;
		case CommonKeys::IMG_PLAYER_LIFE:
			result = "ITEM_HEART.png";
			break;
		case CommonKeys::IMG_GAME_TITLE:
			result = "TXT_GAME_TITLE.png";
			break;
		case CommonKeys::IMG_FX_FIRE:
			result = "FX_FIRE.png";
			break;
		default:
			break;
	}
	return result;
}

PlayerBall* CommonKeys::setPlayerType(Entity* ent,string str)
{
	if(str == "Base")
	{
		ent = new PlayerBall();
	}
	else if(str == "")
	{
	}
	return (PlayerBall*)ent;
}

Event* CommonKeys::setEventType(Entity* ent,string str, LevelScene* level)
{
	if(str == "LevelStart")
	{
		ent = new LevelStartEvent(level);
	}
	else if(str == "LevelEnd")
	{
		ent = new LevelEndEvent(level);
	}
	return (Event*)ent;
}

Background* CommonKeys::setBackgroundType(Entity* ent,string str)
{
	return (Background*)ent;
}

Bar* CommonKeys::setBarType(Entity* ent,string str,LevelScene* level)
{
	if(str == "StartBar")
	{
		ent = new StartBar();
	}
	else if(str == "EndBar")
	{
		ent = new EndBar();
	}
	else if(str == "BlockBar")
	{
		ent = new BlockBar();
	}
	else
	{
		ent = new Bar();
	}
	((Bar*)ent)->_level = level;
	return (Bar*)ent;
}

Item* CommonKeys::setItemType(Entity* ent,string str)
{
	if(str == "Star")
	{
		ent = new StarItem();
	}
	else if(str == "Bomb")
	{
		ent = new Bomb();
	}
	return (Item*)ent;
}


Entity* CommonKeys::stringToEntity(CPLC_TYPE type, string str, LevelScene* level)
{
	Entity* ent = new Entity();

	switch (type)
	{
		case CommonKeys::CPL_PLAYER:
			return setPlayerType(ent,str);		
			break;
		case CommonKeys::CPL_EVENT:
			return setEventType(ent,str,level);		
			break;
		case CommonKeys::CPL_BACKGROUND:
			return setBackgroundType(ent,str);		
			break;
		case CommonKeys::CPL_BAR:
			return setBarType(ent,str,level);		
			break;
		case CommonKeys::CPL_ITEM:
			return setItemType(ent,str);		
			break;
		default:
			break;

	}
	return ent;

}