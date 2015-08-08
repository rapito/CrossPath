#pragma once

#include <cocos2d.h>
#include <SimpleAudioEngine.h>
#include "..\..\Util\CommonKeys.h"
#include "..\..\Entity\Entity.h"
USING_NS_CC;

// Manuel: Porque la clase background extiende de entity y no directamente de CCSprite??
// Robert: Tienes razón, hice el cambio ahora es CCSprite
class Background : public Entity
{

public:
	string _soundFile;
	string _imgFile;

	Background(CommonKeys::IMAGE imgKey, CommonKeys::SOUND soundKey);
	Background(string imgFile, string soundFile);
	~Background(void);
	
	void startBackgroundMusic(bool loop);
	void startBackgroundMusic(void);
	void stopBackgroundMusic();
	void setBackgroundMusic(CommonKeys::SOUND soundKey);
	void toggleBackgroundMusic();
};

