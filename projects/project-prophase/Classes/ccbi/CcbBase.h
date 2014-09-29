//
//  CcbBase.h
//  project-prophase
//
//  Created by jasper on 14-9-29.
//
//

#ifndef __project_prophase__CcbBase__
#define __project_prophase__CcbBase__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Box2D.h"

USING_NS_CC;
USING_NS_CC_EXT;

class CcbBase: public CCLayer, public CCBSelectorResolver, public CCBMemberVariableAssigner, public CCNodeLoaderListener
{
public:
    virtual cocos2d::SEL_MenuHandler onResolveCCBCCMenuItemSelector(CCObject* pTarget, const char* pSelectorName)
	{
        // do nothing
        //CCB_SELECTORRESOLVER_CCMENUITEM_GLUE(this, "onPlay", Playground::btnPlay);
        return NULL;
    }
	
    virtual cocos2d::extension::SEL_CCControlHandler onResolveCCBCCControlSelector(CCObject* pTarget, const char* pSelectorName)
	{
        // do nothing
        return NULL;
    }
	
    virtual bool onAssignCCBMemberVariable(CCObject* pTarget, const char* pMemberVariableName, CCNode* pNode)
	{
        // do nothing
        //CCB_MEMBERVARIABLEASSIGNER_GLUE(this, "apple", CCSprite *, this->apple);
        return NULL;
    }
	
    virtual bool onAssignCCBCustomProperty(CCObject* pTarget, const char* pMemberVariableName, extension::CCBValue* pCCBValue)
	{
        // do nothing
        return false;
    }
	
    virtual void onNodeLoaded(CCNode* pNode, cocos2d::extension::CCNodeLoader* pNodeLoader)
	{
        // do nothing
    }
};
#endif /* defined(__project_prophase__CcbBase__) */
