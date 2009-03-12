//
//  CercaMapHelper.h
//  Cerca
//
//  Created by Peter Zion on 12/03/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "CercaMapPoint.h"

@interface CercaMapHelper : NSObject
{
}

+(CercaMapPoint) mapPointForCoordinate:(CLLocationCoordinate2D)coordinates;

+(CercaMapPoint) mapPoint:(CercaMapPoint)mapPoint
	pannedByPixelDelta:(CGPoint)delta
	atZoomLevel:(CGFloat)zoomLevel;
	
+(CGFloat) mapZoomLevel:(CGFloat)zoomLevel
	scaleByFactor:(CGFloat)scale;
	
@end