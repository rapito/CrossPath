#pragma once
#include "CCModal.h"

class LevelScene;
class ModalManager
{
public:

	static ModalManager* getInstance();
	static ModalManager* _instance;
	CCModal* _pauseModal;

	CCModal* showWinModal(LevelScene* level);
	CCModal* showLoseModal(LevelScene* level);
	CCModal* showPauseModal(LevelScene* level);
	static void nextLevel(GameScene* scene);
	static void retryGame(GameScene* scene);
	static void resumeGame(GameScene* scene);
	~ModalManager(void);

private: 
	ModalManager();
	CCModal* genPauseModal(LevelScene* level);
	CCModal* genWinModal(LevelScene* level);
	CCModal* genLoseModal(LevelScene* level);
};

