//
//  Camera.cpp
//  OpenglES
//
//  Created by Radaev Mikhail on 16.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Camera.hpp"
#include <OpenGLES/ES2/gl.h>
using namespace Render;

Camera::Camera(uint handle):m_Handle(handle)
{
    m_Ortho = new float[16]{
        1, 0,  0, 0,
        0, 1,  0, 0,
        0, 0,  -1, 0,
        0, 0,  0, 1
    };

}

void Camera::SetupOrtho(uint maxX,uint maxY)
{
    float a = 1.0f / maxX;
    float b = 1.0f / maxY;
    
    m_Ortho[0] = a;
    m_Ortho[1] = 0.f;
    m_Ortho[2] = 0.f;
    m_Ortho[3] = 0.f;
    
    m_Ortho[4] = 0.f;
    m_Ortho[5] = b;
    m_Ortho[6] = 0.f;
    m_Ortho[7] = 0.f;
    
    m_Ortho[8] = 0.f;
    m_Ortho[9] = 0.f;
    m_Ortho[10] = -1.f;
    m_Ortho[11] = 0.f;
    
    m_Ortho[12] = 0.f;
    m_Ortho[13] = 0.f;
    m_Ortho[14] = 1.f;
    m_Ortho[15] = 1.f;
    Update();
    
}

void Camera::Update()
{
    GLint projectionUniform = glGetUniformLocation(m_Handle, "Projection");
    glUniformMatrix4fv(projectionUniform, 1, 0, m_Ortho);
}

void Camera::SetupOrtho(float left,float right,float bottom,float top,float near,float far)
{
       
    m_Ortho[0] = 2.f / (right - left);
    m_Ortho[1] = 0.f;
    m_Ortho[2] = 0.f;
    m_Ortho[3] = 0.f;
    
    m_Ortho[4] = 0.f;
    m_Ortho[5] = 2.f / (top - bottom);
    m_Ortho[6] = 0.f;
    m_Ortho[7] = 0.;
    
    m_Ortho[8] = 0.f;
    m_Ortho[9] = 0.f;
    m_Ortho[10] = -2.f / (far - near);
    m_Ortho[11] = 0.f;
    
    m_Ortho[12] = -(right + left)/(right - left);
    m_Ortho[13] = -(top + bottom)/(top - bottom);
    m_Ortho[14] = -(far + near)/(far - near);
    m_Ortho[15] = 1.f;
    Update();
}


Camera::~Camera()
{
    delete m_Ortho;
}


