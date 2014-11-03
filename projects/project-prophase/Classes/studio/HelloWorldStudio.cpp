//
//  HelloWorldStudio.cpp
//  project-prophase
//
//  Created by jasper on 14-10-31.
//
//

#include "HelloWorldStudio.h"

//Scene* HelloWorldStudio::createScene()
//{
//    // 'scene' is an autorelease object
//    auto scene = Scene::create();
//    
//    // 'layer' is an autorelease object
//    auto layer = HelloWorldStudio::create();
//	
//    // add layer as a child to scene
//    scene->addChild(layer);
//	
//    // return the scene
//    return scene;
//}

CCScene* HelloWorldStudio::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorldStudio *layer = HelloWorldStudio::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorldStudio::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
	
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
														  "CloseNormal.png",
														  "CloseSelected.png",
														  this,
														  menu_selector(HelloWorldStudio::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
	
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	
    /////////////////////////////
    // 3. add your codes below...
	
    // add a label shows "Hello World"
    // create and initialize a label
    
//    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
//    
//    // position the label on the center of the screen
//    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - pLabel->getContentSize().height));
//	
//    // add the label as a child to this layer
//    this->addChild(pLabel, 1);
	
	
	CCLabelTTF *l = CCLabelTTF::create("current percent : ", "Arial", 18);
	l->setColor(ccGREEN);
	addChild(l, 1, 10001);
	l->setPosition( ccp(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height - 60) );
//	this->addChild(l);
	
//	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfoAsync("Dragon.png", "Dragon.plist", "Dragon.xml", this, schedule_selector(HelloWorldStudio::dataLoaded));
	
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfoAsync("NewProject.ExportJson", this, schedule_selector(HelloWorldStudio::dataLoaded));
	
	
	
//    // add "HelloWorldStudio" splash screen"
//    CCSprite* pSprite = CCSprite::create("HelloWorldStudio.png");
//	
//    // position the sprite on the center of the screen
//    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//	
//    // add the sprite as a child to this layer
//    this->addChild(pSprite, 0);
    
    return true;
}


void HelloWorldStudio::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void HelloWorldStudio::dataLoaded(float percent)
{
    CCLabelTTF *label = (CCLabelTTF *)getChildByTag(10001);
    if (label)
    {
        char pszPercent[255];
        sprintf(pszPercent, "%s %f", "current percent : ", percent * 100);
        label->setString(pszPercent);
    }
	
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	
//	cocos2d::extension::CCArmature *armature = NULL;
//    armature = cocos2d::extension::CCArmature::create("Dragon");
//    armature->getAnimation()->playWithIndex(1);
//    armature->getAnimation()->setSpeedScale(0.4f);
//    armature->setPosition(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f - 60);
//    armature->setScale(0.6f);
//    addChild(armature);
	
	cocos2d::extension::CCArmature *armature = cocos2d::extension::CCArmature::create("NewProject");
    armature->getAnimation()->play("sheyao_huxi_deyi");
    armature->getAnimation()->setSpeedScale(0.5);
    armature->setPosition(origin.x + visibleSize.width * 0.5f, origin.y + visibleSize.height * 0.5f - 80);
	armature->setScale(2.0f);
	
    /*
     * Set armature's frame event callback function
     * To disconnect this event, just setFrameEventCallFunc(NULL, NULL);
     */
    armature->getAnimation()->setFrameEventCallFunc(this, frameEvent_selector(HelloWorldStudio::onFrameEvent));
	
    addChild(armature);
	
    schedule( schedule_selector(HelloWorldStudio::checkAction) );
}

void HelloWorldStudio::onFrameEvent(cocos2d::extension::CCBone *bone, const char *evt, int originFrameIndex, int currentFrameIndex)
{
    CCLOG("(%s) emit a frame event (%s) at frame index (%d).", bone->getName().c_str(), evt, currentFrameIndex);
	
	
//    if (!this->getActionByTag(FRAME_EVENT_ACTION_TAG) || this->getActionByTag(FRAME_EVENT_ACTION_TAG)->isDone())
//    {
//        this->stopAllActions();
//		
//        CCActionInterval *action =  CCShatteredTiles3D::create(0.2f, CCSizeMake(16,12), 5, false);
//        action->setTag(FRAME_EVENT_ACTION_TAG);
//        this->runAction(action);
//    }
}
void HelloWorldStudio::checkAction(float dt)
{
    if ( this->numberOfRunningActions() == 0 && this->getGrid() != NULL)
        this->setGrid(NULL);
}
