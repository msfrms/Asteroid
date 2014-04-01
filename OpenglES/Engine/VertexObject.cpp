//
//  VertexObject.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 25.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "VertexObject.hpp"

using namespace Core;

FloatVector VertexObject::GetColor()const
{
    return m_Color;
}

FloatVector VertexObject::GetVertexPoints()const
{
    return m_VertextPoints;
}

FloatVector VertexObject::GetTexturePoints()const
{
    return m_TexturePoints;
}
VertexObject::VertexObject(GLuint vertCount,GLenum vertType):m_VertexType(vertType),m_VertexCount(vertCount),m_Radius(50.f)
{
    
}

VertexObject::VertexObject(GLuint vertCount,GLenum vertType,float radius):m_VertexType(vertType),m_VertexCount(vertCount),m_Radius(radius)
{
    
}

VertexObject::VertexObject(VectorArray vertCoord,ColorArray colors,VectorArray textCoord)
{
    for(auto coord:vertCoord)
    {
        m_VertextPoints.push_back(coord.GetX());
        m_VertextPoints.push_back(coord.GetY());
    }
    for(auto coord:textCoord)
    {
        m_TexturePoints.push_back(coord.GetX());
        m_TexturePoints.push_back(coord.GetY());
    }
    for(auto color:colors)
    {
        m_Color.push_back(color.r);
        m_Color.push_back(color.g);
        m_Color.push_back(color.b);
        m_Color.push_back(color.a);
    }
}



void VertexObject::AddTexturePoint(Vector2 coord)
{
    m_TexturePoints.push_back(coord.GetX());
    m_TexturePoints.push_back(coord.GetY());
}

void VertexObject::AddVertexPoint(Vector2 coord)
{
    m_VertextPoints.push_back(coord.GetX());
    m_VertextPoints.push_back(coord.GetY());
}

GLenum VertexObject::GetVertexType()const
{
    return m_VertexType;
}

void VertexObject::AddColor(Color color)
{
    m_Color.push_back(color.r);
    m_Color.push_back(color.g);
    m_Color.push_back(color.b);
    m_Color.push_back(color.a);
}

GLuint VertexObject::GetVertexCount()const
{
    return m_VertexCount;
}




float VertexObject::GetRadius()const
{
    return m_Radius;
}


VertexObject::~VertexObject()
{
    //m_Color.clear();
    m_Color.erase(m_Color.begin(),m_Color.end());
    m_VertextPoints.erase(m_VertextPoints.begin(), m_VertextPoints.end());
    m_TexturePoints.erase(m_TexturePoints.begin(), m_TexturePoints.end());
}






