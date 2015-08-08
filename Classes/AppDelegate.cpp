#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "Scene\MenuScene.h"

USING_NS_CC;
using namespace std;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();
    CCSize designSize;
	vector<string> searchPaths;

	// IMAGE STUFF
	designSize = CCSizeMake(1280, 768);
	pDirector->setOpenGLView(pEGLView);
	if( screenSize.height < designSize.height	||
		screenSize.height > designSize.height	||
		screenSize.width < designSize.width		||
		screenSize.width > designSize.width )
	{
		
		float k = (screenSize.width/designSize.width + 
				  screenSize.height/designSize.height)/2.f; 
		pDirector->setContentScaleFactor(k);
    }

	pEGLView->setDesignResolutionSize
		(designSize.width, designSize.height, kResolutionNoBorder);
    pDirector->setDisplayStats(false);
    pDirector->setAnimationInterval(1.0 / 60);
	// !IMAGE STUFF

	// SEARCH PATHS
	searchPaths.insert(searchPaths.begin(),"sounds");
	searchPaths.insert(searchPaths.begin(),"images");
	searchPaths.insert(searchPaths.begin(),"images/entitiesfolder");
	searchPaths.insert(searchPaths.begin(),"images/Scenefolder");
	CCFileUtils::sharedFileUtils()->setSearchPaths(searchPaths);
	// !SEARCH PATHS

	// USER DATA
	CommonKeys::_CFG_SOUND=CCUserDefault::sharedUserDefault()->getBoolForKey("Sound",true);
	// !USER DATA
	
	srand (time(NULL));
    MenuScene *scene = new MenuScene();
    pDirector->runWithScene(scene->getScene());

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
