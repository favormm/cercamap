//
//  CercaMapView.h
//  Cerca
//
//  Created by Peter Zion on 10/03/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "CercaMapPoint.h"
#import "CercaMapType.h"

#pragma mark Forward Declarations
@protocol CercaMapViewDelegate;

@interface CercaMapView : UIView
{
@private
	int numPoints;
	CGPoint points[2];
	CercaMapPoint centerPoint;
	CGFloat zoomLevel;
	CercaMapType mapType;
}

#pragma mark Public

@property( assign ) CercaMapPoint centerPoint;
@property( assign ) CGFloat zoomLevel;
@property( assign ) CercaMapType mapType;

@end
