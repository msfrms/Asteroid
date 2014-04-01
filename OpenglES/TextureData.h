//
//  TextureData.h
//  OpenglES
//
//  Created by Mikhail Radaev on 18.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/ES2/glext.h>
@interface TextureData : NSObject
@property(nonatomic,assign) GLubyte* data;
@property(nonatomic,assign) CGSize size;
@end
