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
//	//	draw point
//	drawPoint();
	
	return true;
}

void GDraw::drawPoint(CCPoint point, ccColor4F color)
{
	CCLOG("=== drawPoint");
	
	//	set color of the point
	ccDrawColor4F(color.r, color.g, color.b, color.a);
	
	//	draw point
	ccDrawPoint(point);
}

void GDraw::drawLine(CCPoint origin, CCPoint destination, ccColor4F color)
{
	CCLOG("=== drawLine");
	
	//	set color of the line
	ccDrawColor4F(color.r, color.g, color.b, color.a);
	
	//	draw line
	ccDrawLine(origin, destination);
}

void GDraw::drawRect(CCPoint origin, CCPoint destination, ccColor4F color)
{
	CCLOG("=== drawRect");
	
	//	set color of rect
	ccDrawColor4F(color.r, color.g, color.b, color.a);
	
	//	set the array of points
	CCPoint points[] = {ccp(origin.x, origin.y), ccp(destination.x, origin.y), ccp(destination.x, destination.y), ccp(origin.x, destination.y)};
	
	//	draw rect
	ccDrawPoly(points, 4, true);
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

/**
 * draw (called in every frame)
 */
void GDraw::draw(void)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	
	int num = 1000;
	float r = CCRANDOM_0_1();
	float g = CCRANDOM_0_1();
	float b = CCRANDOM_0_1();
	float x1 = 0.0f;
	float y1 = 0.0f;
	float x2 = 0.0f;
	float y2 = 0.0f;
	float gapH = 0.0f;
	float gapV = 0.0f;
	float increment = 0.0f;
	//	----------------- draw point begin -----------------
	//	set the size of point
//	ccPointSize(2.0f);
//	//	Drawing n points
//	for (int i = 0; i < num; i++) {
//		x1 = arc4random() % ((int) winSize.width);
//		y1 = arc4random() % ((int) winSize.height);
//		
//		//	draw point
//		drawPoint(ccp(x1, y1), ccc4f(r, g, b, 1.0f));
//	}
//
//	//	draw single point
//	drawPoint(ccp(winSize.width * 0.5f, winSize.height * 0.5f), ccc4f(1.0f, 0.0f, 0.0f, 1.0f));
	//	----------------- draw point end -----------------
	
	//	----------------- draw line begin -----------------
//	//	set the size of line
//	glLineWidth(1.0f);
//	
//	//	set smooth mode
////	glEnable(GL_Line);
//	
//	//	draw n lines
//	x1 = 0.0f;
//	y1 = 0.0f;
//	x2 = winSize.width * 0.5f;
//	y2 = winSize.height;
//	gapH = winSize.width / num;
//	r = 1.0f;
//	g = 0.0f;
//	b = 0.0f;
//	increment = 1.0f / num;
//	for (int i = 0; i < num; i++) {
//		drawLine(ccp(x1, y1), ccp(x2, y2), ccc4f(r, g, b, 1.0f));
//		x1 += gapH;
//		if (x1 > winSize.width) {
//			x1 -= winSize.width;
//		}
//		y1 += gapV;
//		if (y1 > winSize.height) {
//			y1 -= winSize.height;
//		}
//		x2 += gapH;
//		if (x2 > winSize.width) {
//			x2 -= winSize.width;
//		}
//		y2 -= gapV;
//		if (y2 < 0) {
//			y2 += winSize.height;
//		}
//		r -= increment;
//		g += increment;
//		b += increment;
//	}
//	
//	//	draw single line
//	drawLine(ccp(winSize.width * 0.25f, winSize.height * 0.25f), ccp(winSize.width * 0.75f, winSize.height * 0.75f), ccc4f(1.0f, 0.0f, 0.0f, 1.0f));
	//	----------------- draw line end -----------------
	
	//	----------------- draw rect begin -----------------
	//	set size of rect
	glLineWidth(1.0f);
	
	//	draw n rects
	x1 = winSize.width * 0.1f;
	y1 = winSize.height * 0.1f;
	x2 = winSize.width * 0.5f;
	y2 = winSize.height * 0.5f;
	r = 1.0f;
	g = 0.0f;
	b = 0.0f;
	gapH = 5.0f;
	gapV = 6.0f;
	for (int i = 0; i < num; i++) {
		drawRect(ccp(x1, y1), ccp(x2, y2), ccc4f(r, g, b, 1.0f));
		x1 += gapH;
		if (x1 > winSize.width) {
			x1 -= winSize.width;
		} else if (x1 < 0) {
			x1 += winSize.width;
		}
		y1 += gapV;
		if (y1 > winSize.height) {
			y1 -= winSize.height;
		} else if (y1 < 0) {
			y1 += winSize.height;
		}
		x2 += gapH;
		if (x2 > winSize.width) {
			x2 -= winSize.width;
		} else if (x1 < 0) {
			x2 += winSize.width;
		}
		y2 += gapV;
		if (y2 > winSize.height) {
			y2 -= winSize.height;
		} else if (y1 < 0) {
			y2 += winSize.height;
		}
		r -= 0.05f;
		if (r < 0) {
			r = 1.0f;
		} else if (r > 1.0f) {
			r = 0.0f;
		}
		g -= 0.04f;
		if (g < 0) {
			g = 1.0f;
		} else if (r > 1.0f) {
			g = 0.0f;
		}
		b -= 0.07f;
		if (b < 0) {
			b = 1.0f;
		} else if (r > 1.0f) {
			b = 0.0f;
		}
	}
	
	//	draw single rect
	drawRect(ccp(winSize.width * 0.25f, winSize.height * 0.25f), ccp(winSize.width * 0.75f, winSize.height * 0.75f), ccc4f(1.0f, 0.0f, 0.0f, 1.0f));
	//	----------------- draw rect end -----------------
	
}
