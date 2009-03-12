/*
 *  CercaMapViewDelegate.h
 *  Cerca
 *
 *  Created by Peter Zion on 10/03/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#import "CercaMapPoint.h"
 
#pragma mark Forward Declarations
@class CercaMapView;

@protocol CercaMapViewDelegate

@required

-(void) cercaMapView:(CercaMapView *)cercaMapView
	drawToContext:(CGContextRef)contextRef
	dstRect:(CGRect)dstRect;

-(void) cercaMapView:(CercaMapView *)cercaMapView
	didPanByDelta:(CercaMapPoint)delta;
-(void) cercaMapView:(CercaMapView *)cercaMapView
	didZoomByScale:(CGFloat)scale;

@end
