#include "Background.h"

Background::Background(CommonKeys::IMAGE imgKey, CommonKeys::SOUND soundKey)
{

	setBackgroundMusic(soundKey);
	initWithFile(CommonKeys::keyToString(imgKey));
	setAnchorPoint(ccp(0,0));
	setPosition(0,0);
}

Background::Background(string imgFile, string soundFile)
{
	_soundFile = soundFile;
	_imgFile = imgFile;
	initWithFile(imgFile.c_str());
	setAnchorPoint(ccp(0,0));
	setPosition(0,0);
}

void Background::startBackgroundMusic(bool loop)
{
	if(CommonKeys::_CFG_SOUND)
	{
		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(_soundFile.c_str(),loop);
	}
	else
	{
		CCLog("SOUND Configured OFF!");
	}
}
void Background::startBackgroundMusic(void)
{
	startBackgroundMusic(true);
}

void Background::toggleBackgroundMusic()
{
	if(CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		stopBackgroundMusic();
	}
	else
	{
		startBackgroundMusic();
	}
}

void Background::stopBackgroundMusic()
{
	CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
}

void Background::setBackgroundMusic(CommonKeys::SOUND soundKey)
{
	_soundFile = CommonKeys::keyToString(soundKey);
}

Background::~Background(void)
{
}
