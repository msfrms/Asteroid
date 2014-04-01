//
//  ESView.m
//  OpenglES
//
//  Created by Mikhail Radaev on 11.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#import "ESView.h"
#import <CoreGraphics/CoreGraphics.h>
#import <QuartzCore/QuartzCore.h>
#import "IRenderEngine.hpp"
//#import "TriangleRender.hpp"
#include "IMovable.hpp"
#include "VertexFactory.hpp"
#include "SceneRender.hpp"
#include <iostream>
#include "Define.h"
#include "TouchEvent.hpp"
#include "Resource.h"
#include "Texture.hpp"

#include "GameSceneDirector.hpp"
#include "GameSceneBuilder.hpp"

#define kYes 1
#define kNo 0
using namespace Core;
using namespace std;
using namespace Core;
using namespace Factory;
using namespace Render;
@interface ESView()
{
    EAGLContext* context;
    Render::SceneRender* render;
    GLfloat offset;
    NSTimeInterval lastTime;
}
@property(nonatomic,strong) CADisplayLink* displayLink;
@end
@implementation ESView
+ (Class) layerClass
{
    return [CAEAGLLayer class];
}
+ (id)defaultESView
{
    UIScreen *screen = [UIScreen mainScreen];
    ESView* view = [[ESView alloc] initWithFrame:CGRectMake(0, 0, screen.bounds.size.height, screen.bounds.size.width)];
    return view;
}
- (id) initWithFrame: (CGRect) frame
{
    self = [super initWithFrame:frame];
    if(self)
    {
        CAEAGLLayer* eaglLayer = (CAEAGLLayer*) super.layer;
        eaglLayer.opaque = YES;
        EAGLRenderingAPI api = kEAGLRenderingAPIOpenGLES2;
        context = [[EAGLContext alloc] initWithAPI:api];
        [EAGLContext setCurrentContext:context];
        DeviceOptions devOptions;
        if(UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
        {
            devOptions = DeviceOptions::Pad;
        }
        else
        {
            devOptions = DeviceOptions::Phone;
        }
        Options options(devOptions);
        GameSceneBuilder* builder = new GameSceneBuilder(options);
        GameSceneDirector* levelDirector = new GameSceneDirector(builder);
        levelDirector->BuildScene();
        
        render = levelDirector->GetGameScene();
        render->Initialized(options.GetBackgroundSize().Width, options.GetBackgroundSize().Height);
        
        [context renderbufferStorage:GL_RENDERBUFFER fromDrawable: eaglLayer];
        if(_displayLink == nil)
        {
             _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(drawView:)];
        }
       
        lastTime = _displayLink.timestamp;
        [_displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
        
        delete levelDirector;
        delete builder;
               
    }
    return self;
}

- (void) drawView: (CADisplayLink*) displayLink
{
    if(render->IsLevelEnd())
    {
        UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"Game" message:@"Конец игры! Продолжить игру?" delegate:self cancelButtonTitle:@"Нет" otherButtonTitles:@"Да", nil];
        [alert show];
        displayLink.paused = YES;
        return;
    }

    render->Draw();
    float dt = 0;
    if(lastTime == 0)
    {
        lastTime = displayLink.timestamp;
    }
    dt = displayLink.timestamp - lastTime;
    lastTime = displayLink.timestamp;
    render->Update(dt);
    [context presentRenderbuffer:GL_RENDERBUFFER];
}
- (CGPoint)convertToOpenGLFromView:(CGPoint)coord
{
    CGPoint result;
    result.x = coord.x;
    result.y = coord.y;
    
    return result;
}
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch* touch = [touches anyObject];
    CGPoint point = [self convertToOpenGLFromView:[touch locationInView:self]];
    Core::TouchEvent* e = new TouchEvent(new Vector2(point.x,point.y),Touch::TouchBegin,nullptr);
    render->TouchEvent(e);
    delete e;
    
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch* touch = [touches anyObject];
    CGPoint point = [self convertToOpenGLFromView:[touch locationInView:self]];
    Core::TouchEvent* e = new TouchEvent(new Vector2(point.x,point.y),Touch::TouchEnd,nullptr);
    render->TouchEvent(e);
    delete e;
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    UITouch* touch = [touches anyObject];
    CGPoint point = [self convertToOpenGLFromView:[touch locationInView:self]];
    Core::TouchEvent* e = new TouchEvent(new Vector2(point.x,point.y),Touch::TouchMoved,nullptr);
    render->TouchEvent(e);
    delete e;
   
}

- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex
{
    switch (buttonIndex) {
        case kYes:
        {
            render->RestartLevel();
            self.displayLink.paused = NO;
        }break;
        case kNo:
        {
            exit(0);
        }break;
            
        default:
            break;
    }
}


- (void)dealloc
{
    delete render;
}
@end
