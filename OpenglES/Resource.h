//
//  Resource.h
//  OpenglES
//
//  Created by Radaev Mikhail on 17.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//
#pragma once
#import <Foundation/Foundation.h>
#import "TextureData.h"
@interface Resource : NSObject
@property(nonatomic,readonly) TextureData* data;
+ (id)resource;
- (void)loadImage:(NSString*)imageName;
@end
