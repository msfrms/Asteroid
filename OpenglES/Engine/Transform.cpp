//
//  Transform.cpp
//  OpenglES
//
//  Created by Radaev Mikhail on 15.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Transform.hpp"
using namespace Core;

Transform::Transform(GLuint handle):m_ProgramHandle(handle),m_Matrix(new Matrix())
{
}

Transform::Transform(GLuint handle,Matrix* matrix):m_ProgramHandle(handle),m_Matrix(matrix)
{
    
}

void Transform::Translate(Vector2 coord)
{
    m_Matrix->TranslateBy(&coord);
}
void Transform::Scale(Vector2 scale)
{
    m_Matrix->ScaleBy(&scale);
}
void Transform::SetIdentity()
{
    m_Matrix->SetIdentity();
}
void Transform::Update()
{
    GLint modelviewUniform = glGetUniformLocation(m_ProgramHandle, "Modelview");
    glUniformMatrix4fv(modelviewUniform, 1, 0, m_Matrix->GetMat4());
}

Transform::~Transform()
{
    delete m_Matrix;
}