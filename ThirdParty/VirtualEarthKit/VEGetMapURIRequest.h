//
//  VEGetMapURIRequest.h
//  VirtualEarthKit
//
//  Created by Colin Cornaby on 10/29/08.
//  Copyright 2008 Consonance Software. All rights reserved.
//

//Redistribution and use in source and binary forms, with or without
//modification, are permitted provided that the following conditions
//are met:
//1. Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
//2. Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
//3. Neither the name of the author nor the names of any co-contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
//THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
//ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
//FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
//OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
//HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
//LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
//OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
//SUCH DAMAGE.
//

#import <Foundation/Foundation.h>
#import <VirtualEarthKit/VEService.h>

#import <Foundation/Foundation.h>
#import <VirtualEarthKit/VERequest.h>
#import <VirtualEarthKit/VEImageryMetadataRequest.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface VEGetMapURIRequest : VERequest {
	CLLocation * m_center;
	int m_zoomLevel;
	NSArray *m_pushpins;
	CGSize m_mapSize;
	int m_mapType;
}

@property CGSize mapSize;
@property (assign) int zoomLevel;
@property (retain) NSArray *pushpins;
@property (retain) CLLocation * center;

@end
