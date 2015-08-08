#include "ModalManager.h"
#include "..\Scene\LevelScene.h"

ModalManager* ModalManager::_instance;

ModalManager* ModalManager::getInstance()
{
	return !_instance ? (_instance=new ModalManager()):_instance;
}

ModalManager::ModalManager()
{
	
}

CCModal* ModalManager::showWinModal(LevelScene* level)
{
	CCModal* modal = genWinModal(level);
	modal->addToScene(level);
	return modal;
}

CCModal* ModalManager::showLoseModal(LevelScene* level)
{
	CCModal* modal = genLoseModal(level);
	modal->addToScene(level);
	return modal;
}

CCModal* ModalManager::showPauseModal(LevelScene* level)
{
	CCModal* modal = genPauseModal(level);
	modal->addToScene(level);
	return modal;
}


CCModal* ModalManager::genWinModal(LevelScene* level)
{
	vector<CCButton*> btnVector;
	CCButton *btnQuit = new CCButton("Quit");	
	CCButton *btnRetry = new CCButton("Retry");
	CCButton *btnNext = new CCButton("Next");
	
	btnQuit->assignAction(CommonCallbacks::btnAtnBack,level);
	btnRetry->assignAction(retryGame,level);
	btnNext->assignAction(nextLevel,level);
	
	btnVector.push_back(btnQuit);
	btnVector.push_back(btnRetry);

	if(level->_nextLevel.size()>0)
	{
		btnVector.push_back(btnNext);
	}
	
    return new CCModal("Game Won",btnVector);
}

CCModal* ModalManager::genLoseModal(LevelScene* level)
{
	vector<CCButton*> btnVector;
	CCButton *btnQuit = new CCButton("Quit");	
	CCButton *btnRetry = new CCButton("Retry");
	
	btnQuit->assignAction(CommonCallbacks::btnAtnBack,level);
	btnRetry->assignAction(retryGame,level);
	
	btnVector.push_back(btnQuit);
	btnVector.push_back(btnRetry);
	
    return new CCModal("You Lose.. Ugh!",btnVector);
}

CCModal* ModalManager::genPauseModal(LevelScene* level)
{
	// Inicializamos los botones y el label del modal
	// para asignarlo como atributo en el Scene
	// se hizo de esta forma para trabajar con los callbacks de los botones
	// sin hacer cambios drasticos en estos
	// ya que el callback debe de ser statico y recibir un GameScene

	vector<CCButton*> btnVector;
	CCButton *btnQuit = new CCButton("Quit");	
	CCButton *btnSound = new CCButton("Sound");
	CCButton *btnRetry = new CCButton("Retry");
	CCButton *btnResume = new CCButton("Resume");
	
	btnRetry->assignAction(retryGame,level);
	btnResume->assignAction(resumeGame,level);
	btnQuit->assignAction(CommonCallbacks::btnAtnBack,level);
	btnSound->assignAction(CommonCallbacks::btnAtnSound,level);
	
	btnVector.push_back(btnResume);
	btnVector.push_back(btnRetry);
	btnVector.push_back(btnSound);
	btnVector.push_back(btnQuit);
	
    return new CCModal("Pause",btnVector);
}

void ModalManager::nextLevel(GameScene* scene)
{
	// Reseteo de nivel
	LevelScene* refLevel = (LevelScene*)scene;
	string filename = refLevel->_nextLevel;
	LevelScene* newLevel = LevelManager::getInstance()->loadLevel(filename);
	
	
	CommonCallbacks::navigateToScene(newLevel->getScene());
	
}

void ModalManager::retryGame(GameScene* scene)
{
	// Reseteo de nivel
	LevelScene* refLevel = (LevelScene*)scene;
	resumeGame(scene);
	refLevel->_playerLife->setNewLife(&(refLevel->_playerLives=3));
	refLevel->resetGame();	
}

void ModalManager::resumeGame(GameScene* scene)
{
	// Funcion resume, callback para el boton resume
	// se remueve el modal de la pantalla y se continua con el juego
	LevelScene* level = (LevelScene*)scene;
	level->_currentModal->cleanButtonsUp(level);
	level->removeChild(level->_currentModal);
	level->_currentModal = 0;
	level->resumeGame();
}

ModalManager::~ModalManager(void)
{
}
