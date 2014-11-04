//
//  StudioUITest.cpp
//  project-prophase
//
//  Created by jasper on 14-11-4.
//
//

#include "StudioUITest.h"

CCScene* StudioUITest::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    StudioUITest *layer = StudioUITest::create();
	
    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool StudioUITest::init()
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
														  menu_selector(StudioUITest::menuCloseCallback));
    
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
	
	
	std::string m_filePathName = "ccs-res/ui/LoadSceneEdtiorFileTest/FishJoy2.json";  //default is json
    CCNode* m_rootNode = SceneReader::sharedSceneReader()->createNodeWithSceneFile(m_filePathName.c_str());
	if (m_rootNode == NULL)
	{
		return false;
	}
	
	this->addChild(m_rootNode);
	cocos2d::extension::ActionManager::shareManager()->playActionByName("startMenu_1.json","Animation1");
    
    return true;
}


void StudioUITest::menuCloseCallback(CCObject* pSender)
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
