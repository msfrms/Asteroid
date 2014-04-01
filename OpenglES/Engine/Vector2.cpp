//
//  Vector3.m
//  OpenglES
//
//  Created by Admin on 12/06/2013.
//  Copyright (c) 2013 IDScan. All rights reserved.
//


#include "Vector2.hpp"
#include <cmath>
using namespace std;
using namespace Math;

Vector2::Vector2(GLfloat x,GLfloat y):m_X(x),m_Y(y)
{
    
}

void Vector2::SetPosition(Vector2 pos)
{
    m_X = pos.GetX();
    m_Y = pos.GetY();
}
GLfloat Vector2::GetX()const
{
    return m_X;
}

GLfloat Vector2::GetY()const
{
    return m_Y;
}



float Vector2::Distance(Vector2 pos1,Vector2 pos2)
{
    float dx = pos2.GetX() - pos1.GetX();
    float dy = pos2.GetY() - pos1.GetY();
   
    return sqrt(dx*dx + dy*dy);
}


bool Vector2::operator ==(const Vector2& vec3)
{
    return m_X == vec3.GetX() && m_Y == vec3.GetY();
}




