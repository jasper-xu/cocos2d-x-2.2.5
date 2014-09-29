//
//  BWTexturedSliderCell.h
//  BWToolkit
//
//  Created by Brandon Walkin (www.brandonwalkin.com)
//  All code is provided under the New BSD license.
//

#import <Cocoa/Cocoa.h>

@interface BWTexturedSliderCell : NSSliderCell 
{
	BOOL isPressed;
	int trackHeight;
    float x;
    id delegate;
}

@property int trackHeight;
@property float x;
@property id delegate;

@end
