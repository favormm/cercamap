//
//  CercaMapView.m
//  Cerca
//
//  Created by Peter Zion on 10/03/09.
//  Copyright 2009 Peter Zion. All rights reserved.
//

#import "CercaMapView.h"
#import "CercaMapGenerator.h"
#import "CercaMapHelper.h"

@implementation CercaMapView

#pragma mark Private

-(void) cercaMapGeneratorDidRefresh:(id)sender
{
	[self setNeedsDisplay];
}

+(CGFloat) distanceFromPoint:(CGPoint)point1 toPoint:(CGPoint)point2
{
	return sqrt( (point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y) );
}

+(CGPoint) midpointBetweenPoint:(CGPoint)point1 andPoint:(CGPoint)point2
{
	return CGPointMake( (point1.x + point2.x)/2, (point1.y + point2.y)/2 );
}

+(CGPoint) closestPointToPoint:(CGPoint)point betweenPoint:(CGPoint)point1 andPoint:(CGPoint)point2
{
	CGFloat point1Dist = [self distanceFromPoint:point toPoint:point1];
	CGFloat point2Dist = [self distanceFromPoint:point toPoint:point2];
	if ( point1Dist < point2Dist )
		return point1;
	else
		return point2;
}

-(void) initialize
{
	self.multipleTouchEnabled = YES;

	[CercaMapGenerator addRefreshObserver:self selector:@selector(cercaMapGeneratorDidRefresh:)];
	
	CLLocationCoordinate2D coordinate;
	coordinate.latitude = 44.23;
	coordinate.longitude = -76.5;

	zoomLevel = CM_ZOOM_LEVEL_NEIGHBORHOOD;
	[self setCenterCoordinate:coordinate];
	mapType = CM_MAP_TYPE_DEFAULT;
}

#pragma mark Lifecycle

-(id) init
{
	if ( self == [super init] )
		[self initialize];
	return self;
}

-(void) awakeFromNib
{
	[self initialize];
}

-(void) dealloc
{
	[CercaMapGenerator removeRefreshObserver:self];
	[super dealloc];
}

#pragma mark CercaMapView - Parameters

@dynamic centerPoint;

-(CercaMapLocation) centerPoint
{
	return centerPoint;
}

-(void) setCenterPoint:(CercaMapLocation)_
{
	centerPoint = _;
	[self setNeedsDisplay];
}

@dynamic zoomLevel;

-(CercaMapZoomLevel) zoomLevel
{
	return zoomLevel;
}

-(void) setZoomLevel:(CercaMapZoomLevel)_
{
	zoomLevel = _;
	[self setNeedsDisplay];
}

@dynamic mapType;

-(CercaMapType) mapType
{
	return mapType;
}

-(void) setMapType:(CercaMapType)_
{
	mapType = _;
	[self setNeedsDisplay];
}

-(void) setCenterCoordinate:(CLLocationCoordinate2D)coordinate
{
	centerPoint = [CercaMapHelper mapPointForCoordinate:coordinate];
	[self setNeedsDisplay];
}

#pragma mark UIView

-(void) drawRect:(CGRect)rect
{
	[CercaMapGenerator drawToDstRect:self.bounds
		centerPoint:centerPoint
		zoomLevel:zoomLevel
		mapType:mapType];
}

-(void) touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event
{
	numPoints = 0;
	for ( UITouch *touch in touches )
	{
		points[numPoints++] = [touch locationInView:self];
		if ( numPoints == 2 )
			break;
	}
}

-(void) touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event
{
	int newNumPoints = 0;
	CGPoint newPoints[2];
	for ( UITouch *touch in [event allTouches] )
	{
		newPoints[newNumPoints++] = [touch locationInView:self];
		if ( newNumPoints == 2 )
			break;
	}
	
	if ( newNumPoints >= 1 && numPoints >= 1 )
	{
		CGPoint startPoint, endPoint;
		if ( numPoints == 2 )
		{
			if ( newNumPoints == 2 )
			{
				startPoint = [CercaMapView midpointBetweenPoint:points[0] andPoint:points[1]];
				endPoint = [CercaMapView midpointBetweenPoint:newPoints[0] andPoint:newPoints[1]];
			}
			else
			{
				startPoint = [CercaMapView closestPointToPoint:newPoints[0] betweenPoint:points[0] andPoint:points[1]];
				endPoint = newPoints[0];
			}
		}
		else
		{
			if ( newNumPoints == 2 )
			{
				startPoint = points[0];
				endPoint = [CercaMapView closestPointToPoint:points[0] betweenPoint:newPoints[0] andPoint:newPoints[1]];
			}
			else
			{
				startPoint = points[0];
				endPoint = newPoints[0];
			}
		}
		CGPoint pointDelta = CGPointMake( startPoint.x - endPoint.x, startPoint.y - endPoint.y );
		if ( pointDelta.x != 0 || pointDelta.y != 0 )
		{
			centerPoint = [CercaMapHelper mapLocation:centerPoint pannedByPointDelta:pointDelta atZoomLevel:zoomLevel];
			[self setNeedsDisplay];
		}
	}
	
	if ( newNumPoints == 2 && numPoints == 2 )
	{
		CGFloat startDistance = [CercaMapView distanceFromPoint:points[0] toPoint:points[1]];
		CGFloat endDistance = [CercaMapView distanceFromPoint:newPoints[0] toPoint:newPoints[1]];
		zoomLevel = [CercaMapHelper mapZoomLevel:zoomLevel scaleByStartPointDistance:startDistance endPointDistance:endDistance];
		[self setNeedsDisplay];
	}

	numPoints = newNumPoints;
	for ( int i=0; i<numPoints; ++i )
		points[i] = newPoints[i];
}

@end
