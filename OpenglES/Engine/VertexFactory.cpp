//
//  GameObjectFactory.m
//  OpenglES
//
//  Created by Mikhail Radaev on 13.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "VertexFactory.hpp"
#include <cmath>
using namespace Factory;
using namespace Math;

VertexObject* VertexFactory::CreateVertexObject(float size)
{

    VertexObject *vertexObject = new VertexObject(4,GL_TRIANGLE_STRIP,size * 0.5f);
    vertexObject->AddVertexPoint(Vector2(0.f, size));
    vertexObject->AddVertexPoint(Vector2(size, size));
    vertexObject->AddVertexPoint(Vector2(0.f, 0.f));
    vertexObject->AddVertexPoint(Vector2(size, 0.f));
    
    vertexObject->AddTexturePoint(Vector2(0, 0));
    vertexObject->AddTexturePoint(Vector2(1, 0));
    vertexObject->AddTexturePoint(Vector2(0, 1));
    vertexObject->AddTexturePoint(Vector2(1, 1));
    Color color(1,0,0,1);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    
    return vertexObject;
    
}

VertexObject* VertexFactory::CreateVertexBullet(float size)
{
    
    VertexObject *vertexObject = new VertexObject(4,GL_TRIANGLE_STRIP,size * 0.5f);
    
    vertexObject->AddVertexPoint(Vector2(0.f, size));
    vertexObject->AddVertexPoint(Vector2(size, size));
    vertexObject->AddVertexPoint(Vector2(0.f, 0.f));
    vertexObject->AddVertexPoint(Vector2(size, 0.f));
    
    vertexObject->AddTexturePoint(Vector2(0, 0));
    vertexObject->AddTexturePoint(Vector2(1, 0));
    vertexObject->AddTexturePoint(Vector2(0, 1));
    vertexObject->AddTexturePoint(Vector2(1, 1));
    
    Color color(1,0,0,1);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    
    return vertexObject;


}

VertexObject * VertexFactory::CreateVertexBackground(float width,float height)
{
    VertexObject *vertexObject = new VertexObject(4,GL_TRIANGLE_STRIP,0.f);
    
    vertexObject->AddVertexPoint(Vector2(width, 0.f));
    vertexObject->AddVertexPoint(Vector2(width, height));
    vertexObject->AddVertexPoint(Vector2(0.f, 0.f));
    vertexObject->AddVertexPoint(Vector2(0.f, height));
    
    vertexObject->AddTexturePoint(Vector2(0, 0));
    vertexObject->AddTexturePoint(Vector2(1, 0));
    vertexObject->AddTexturePoint(Vector2(0, 1));
    vertexObject->AddTexturePoint(Vector2(1, 1));
    
    Color color(1,0,0,1);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    return vertexObject;
}

VertexObject* VertexFactory::CreateFragmentOfAsteroid(float size)
{
    VertexObject *vertexObject = new VertexObject(4,GL_TRIANGLE_STRIP,size * 0.5f);
    
    vertexObject->AddVertexPoint(Vector2(0.f, size));
    vertexObject->AddVertexPoint(Vector2(size, size));
    vertexObject->AddVertexPoint(Vector2(0.f, 0.f));
    vertexObject->AddVertexPoint(Vector2(size, 0.f));
    
    vertexObject->AddTexturePoint(Vector2(0, 0));
    vertexObject->AddTexturePoint(Vector2(1, 0));
    vertexObject->AddTexturePoint(Vector2(0, 1));
    vertexObject->AddTexturePoint(Vector2(1, 1));
    
    Color color(1,0,0,1);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    vertexObject->AddColor(color);
    
    return vertexObject;

}



