//
//  GDraw.cpp
//  project-prophase
//
//  Created by jasper on 14-9-25.
//
//

#include "GDraw.h"

GDraw::~GDraw()
{
	
}

GDraw::GDraw()
{

}

GDraw* GDraw::create()
{
	GDraw* instance = new GDraw();
	if (instance && instance->init()) {
		instance->autorelease();
		return instance;
	}
	CC_SAFE_DELETE(instance);
	return NULL;
}

bool GDraw::init()
{
	
	return true;
}

void GDraw::drawPoint()
{

}

void GDraw::drawLine()
{

}

void GDraw::drawPlane()
{

}

void GDraw::drawCircleLine()
{

}

void GDraw::drawCirclePlane()
{

}

void GDraw::drawBezierCurve()
{

}

void GDraw::drawImage(const char *imageFileName)
{

}

void GDraw::zoomImage(const char *imageFileName)
{

}

void GDraw::mirrorOfImage(const char *imageFileName)
{
	
}

void GDraw::clipImage(const char *imageFileName, cocos2d::CCPoint &point, cocos2d::CCRect &rect)
{

}
