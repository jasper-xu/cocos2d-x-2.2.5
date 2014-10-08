#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GDraw.h"
#include "IntroLoader.h"
#include "Intro.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    CCDirector* pDirector = CCDirector::sharedDirector();
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();

    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
//    CCScene *pScene = HelloWorld::scene();
	
	//	测试绘制接口
//	CCScene *pScene = CCScene::create();
//    
//    GDraw* draw = GDraw::create();
//	pScene->addChild(draw);
	
	//	测试cocosbuilder
	CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
	ccNodeLoaderLibrary->registerCCNodeLoader("CcbBase", IntroLoader::loader());
	
	CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
	
//	CCNode* node = ccbReader->readNodeGraphFromFile("MainScene.ccbi");
	CCNode* node = ccbReader->readNodeGraphFromFile("HelloWorld.ccbi");
	ccbReader->release();
	
	CCScene *pScene = CCScene::create();
	pScene->addChild(node);
	
    // run
    pDirector->runWithScene(pScene);

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
