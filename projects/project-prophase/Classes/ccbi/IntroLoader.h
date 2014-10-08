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
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(IntroLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(CcbBase);
};
#endif /* defined(__project_prophase__IntroLoader__) */
