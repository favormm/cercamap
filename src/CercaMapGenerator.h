//
//  CercaMapGenerator.h
//  Cerca
//
//  Created by Peter Zion on 12/03/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CercaMapPoint.h"
#import "CercaMapType.h"

#pragma mark Forward Declarations
@class CercaMapQuad;
@protocol CercaMapGeneratorDelegate;

@interface CercaMapGenerator : NSObject
{
}

+(void) drawToDstRect:(CGRect)dstRect
	centerPoint:(CercaMapPoint)centerPoint
	zoomLevel:(CGFloat)zoomLevel
	mapType:(CercaMapType)mapType;

+(NSNotificationCenter *) refreshNotificationCenter;
+(NSString *) refreshNotificationName;
+(void) addRefreshObserver:(id)observer
	selector:(SEL)selector;
+(void) removeRefreshObserver:(id)observer;

+(void) didReceiveMemoryWarning;

@end
