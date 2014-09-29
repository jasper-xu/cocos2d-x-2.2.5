//
//  GDraw.h
//  project-prophase
//
//  Created by jasper on 14-9-25.
//
//

#ifndef __project_prophase__GDraw__
#define __project_prophase__GDraw__

#include "cocos2d.h"
USING_NS_CC;

class GDraw : public cocos2d::CCLayer
{
public:
	/**
	 * GDraw destructor
	 */
	~GDraw();
	/**
	 * GDraw constructor
	 */
	GDraw();
	
	/**
	 * create
	 */
	static GDraw* create();
	
	/**
	 * draw (called in every frame)
	 */
	virtual void draw(void);
	
private:
	/**
	 * GDraw initialise
	 */
	virtual bool init();
	
	/**
	 * draw point
	 */
	void drawPoint(CCPoint point, ccColor4F color);
	
	/**
	 * draw line
	 */
	void drawLine(CCPoint origin, CCPoint destination, ccColor4F color);
	
	/**
	 * draw rect
	 */
	void drawRect(CCPoint origin, CCPoint destination, ccColor4F color);
	
	/**
	 * fill rect
	 */
	void fillRect(CCPoint origin, CCPoint destination, ccColor4F color);
	
	/**
	 * draw Circle line
	 */
	void drawCircleLine();
	
	/**
	 * draw Circle plane
	 */
	void drawCirclePlane();
	
	/**
	 * draw Bézier curve
	 */
	void drawBezierCurve();
	
	/**
	 * draw image
	 */
	void drawImage(const char* imageFileName);
	
	/**
	 * zoom image
	 */
	void zoomImage(const char* imageFileName);
	
	/**
	 * draw the mirror of the image
	 */
	void mirrorOfImage(const char* imageFileName);
	
	/**
	 * clip image
	 */
	void clipImage(const char* imageFileName, CCPoint& point, CCRect& rect);
	
};

#endif /* defined(__project_prophase__GDraw__) */
