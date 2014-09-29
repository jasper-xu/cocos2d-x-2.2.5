//
//  Intro.h
//  project-prophase
//
//  Created by jasper on 14-9-29.
//
//

#ifndef __project_prophase__Intro__
#define __project_prophase__Intro__

#include "CcbBase.h"
#include <iostream>
class Intro: public CcbBase
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(Intro, create);
    
    Intro()
	{
		
	}
    
    virtual ~Intro()
	{
	
	}
    
    void btnPlay(CCObject *pSender)
	{  //这个是回调函数,
//        CCDirector::sharedDirector()->replaceScene(PlaygroundLoader::loadCcbi());
		CCLOG("==== 按钮点击");
    }
    
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
	{
        CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "btnPlay", Intro::btnPlay);  // 把btnPlay对应回调函数,btnPlay的设置在“编辑ccb文件－－按钮”中介绍了
    }
};

#endif /* defined(__project_prophase__Intro__) */
