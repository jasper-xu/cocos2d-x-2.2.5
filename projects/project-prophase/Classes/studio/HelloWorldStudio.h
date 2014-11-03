//
//  HelloWorldStudio.h
//  project-prophase
//
//  Created by jasper on 14-10-31.
//
//

#ifndef __project_prophase__HelloWorldStudio__
#define __project_prophase__HelloWorldStudio__

#include <iostream>
#include "cocos2d.h"

class HelloWorldStudio : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorldStudio);
	
	void dataLoaded(float percent);
};

#endif /* defined(__project_prophase__HelloWorldStudio__) */
