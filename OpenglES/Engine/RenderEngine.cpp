//
//  RenderEngine.m
//  OpenglES
//
//  Created by Mikhail Radaev on 10.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//
#include "RenderEngine.hpp"
using namespace Render;

RenderEngine::RenderEngine():GameObject(),m_Texture(nullptr)
{
    glGenRenderbuffers(1, &m_renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, m_renderBuffer);
}


void RenderEngine::Initialized(uint width,uint height)
{
    
    
    glGenFramebuffers(1, &m_frameBuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, m_frameBuffer);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_renderBuffer);
    glViewport(0, 0, width, height);
}

void RenderEngine::Draw()
{
    glClearColor(0, 104.0/255.0, 55.0/255.0, 1.0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glEnable(GL_ALPHA);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void RenderEngine::Update(float dt)
{
    
}

RenderEngine::~RenderEngine()
{
    
}
