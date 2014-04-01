//
//  Resource.m
//  OpenglES
//
//  Created by Radaev Mikhail on 17.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#import "Resource.h"
@interface Resource()
@property(nonatomic,readwrite) TextureData* data;
@end
@implementation Resource
+ (id)resource
{
    Resource* resource = [self new];
    resource.data = [TextureData new];
    return resource;
}

- (void)loadImage:(NSString *)imageName
{
    
     CGImageRef spriteImage = [UIImage imageNamed:imageName].CGImage;
    size_t width = CGImageGetWidth(spriteImage);
    size_t height = CGImageGetHeight(spriteImage);
    
    GLubyte * spriteData = (GLubyte *) calloc(width*height*4, sizeof(GLubyte));
    
    CGContextRef spriteContext = CGBitmapContextCreate(spriteData, width, height, 8, width*4, CGImageGetColorSpace(spriteImage), kCGImageAlphaPremultipliedLast);
    
    // 3
    CGContextDrawImage(spriteContext, CGRectMake(0, 0, width, height), spriteImage);
    
    CGContextRelease(spriteContext);
    
    free(_data.data);
    _data.data = spriteData;
    _data.size = CGSizeMake(width, height);
   // CGImageRelease(spriteImage);
    
}
- (void)dealloc
{
    free(_data.data);
}
@end
