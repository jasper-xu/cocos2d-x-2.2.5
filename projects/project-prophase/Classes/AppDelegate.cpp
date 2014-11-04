#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "GDraw.h"
#include "IntroLoader.h"
#include "Intro.h"
#include "HelloWorldStudio.h"
#include "StudioUITest.H"

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
	
//	//	测试cocosbuilder
//	CCNodeLoaderLibrary* ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
//	ccNodeLoaderLibrary->registerCCNodeLoader("CcbBase", IntroLoader::loader());
//	
//	CCBReader* ccbReader = new CCBReader(ccNodeLoaderLibrary);
//	
////	CCNode* node = ccbReader->readNodeGraphFromFile("MainScene.ccbi");
//	CCNode* node = ccbReader->readNodeGraphFromFile("HelloWorld.ccbi");
//	ccbReader->release();
//	
//	CCLabelTTF* ttf = dynamic_cast<CCLabelTTF*>(node->getChildByTag(123));
//	if (ttf) {
//		ttf->setString("大家好");
//	}
//	
//	CCScene *pScene = CCScene::create();
//	pScene->addChild(node);
//	
//	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//	
//	//	粒子系统
//	CCParticleSystem* particle = CCParticleSystemQuad::create("smoke.plist");
//	particle->setPosition(ccp(winSize.width * 0.5f, winSize.height * 0.5f));
//	pScene->addChild(particle);
	
//	//	骨骼动画
//	CCScene *pScene = CCScene::create();
//    
//    HelloWorldStudio *helloworldStudio = HelloWorldStudio::create();
//	pScene->addChild(helloworldStudio);
	
	//	Studio UI
	CCScene *pScene = CCScene::create();
    
    StudioUITest* ui = StudioUITest::create();
	pScene->addChild(ui);
	
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
