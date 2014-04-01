//
//  Bullet.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 18.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Bullet.hpp"
#include "VertexFactory.hpp"
#include <cmath>
#define kOffsetPath 10
using namespace Render;
using namespace Factory;
Bullet::Bullet(Program* handle):GameObjectRender(handle)
{
    
}
Bullet::Bullet(Program* handle,VertexObject* vertex):GameObjectRender(handle,vertex),m_IsFly(false)
{
   
}
void Bullet::Initialized(uint width,uint height)
{
    GameObjectRender::Initialized(width, height);
    
}
void Bullet::Draw()
{
    //если пуля летит то отображаем ее
    if(m_IsFly)
    {
        GameObjectRender::Draw();
    }
    
}
void Bullet::Fire()
{
    m_IsFly = true;
}
bool Bullet::IsFly()const
{
    return m_IsFly;
}
void Bullet::Update(float dt)
{
    GetPosition()->SetPosition(Vector2(GetPosition()->GetX(), GetPosition()->GetY() - kOffsetPath));
    if(GetPosition()->GetY() <  0)
    {
        m_IsFly = false;
    }
}

void Bullet::GenerateContact(GameObject* object)
{
   
}

TypeGameObject Bullet::Type()const
{
    return TypeGameObject::Bullet;
}

float Bullet::GetRadius()const
{
    return m_Radius;
}

bool Bullet::IsCollideObject(GameObject* object)
{
       return false;
}

Bullet::~Bullet()
{
    
}



