//
//  IntroLoader.h
//  project-prophase
//
//  Created by jasper on 14-9-29.
//
//

#ifndef __project_prophase__IntroLoader__
#define __project_prophase__IntroLoader__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "IntroLoader.h"
#include "Intro.h"
//#include "Box2D.h"

USING_NS_CC;
USING_NS_CC_EXT;

class IntroLoader : public cocos2d::extension::CCLayerLoader {
public:
    static CCScene* loadCcbi() {
        CCNodeLoaderLibrary * ccNodeLoaderLibrary = CCNodeLoaderLibrary::newDefaultCCNodeLoaderLibrary();
        ccNodeLoaderLibrary->registerCCNodeLoader("Intro", IntroLoader::loader());
        
        /* Create an autorelease CCBReader. */
        cocos2d::extension::CCBReader* ccbReader = new cocos2d::extension::CCBReader(ccNodeLoaderLibrary);
        
        /* Read a ccbi file. */
        CCNode * node = ccbReader->readNodeGraphFromFile("MainScene.ccbi");
        ccbReader->release();
        
        CCScene* scene = CCScene::create();
        scene->addChild(node);
        
        return scene;
    }
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(IntroLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(Intro);
};
#endif /* defined(__project_prophase__IntroLoader__) */
