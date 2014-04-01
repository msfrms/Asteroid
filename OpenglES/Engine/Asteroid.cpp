//
//  Asteroid.cpp
//  OpenglES
//
//  Created by Radaev Mikhail on 16.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Asteroid.hpp"
#include "VertexFactory.hpp"
#include <cmath>
#include "Define.h"
#define kAsteroidVelocity 1
using namespace Render;
using namespace Factory;
Asteroid::Asteroid(Program* handle):GameObjectRender(handle)
{
}
Asteroid::Asteroid(Program* handle,VertexObject* vertex):GameObjectRender(handle,vertex)
{
    
}
void Asteroid::Initialized(uint width,uint height)
{
    GameObjectRender::Initialized(width, height);
}
void Asteroid::Draw()
{
    GameObjectRender::Draw();
    //если астеройд "мертв" отображаем осколки
    if(this->GetHealth()->IsDead())
    {
        for(auto fragment:m_FragmentsOfAsteroid)
        {
            fragment->Draw();
        }
    }
}

void Asteroid::Update(float dt)
{
   this->Move(Vector2(GetPosition()->GetX(), GetPosition()->GetY() + kAsteroidVelocity));
}

void Asteroid::Move(Vector2 pos)
{
    GameObjectRender::Move(pos);
    for(auto fragment:m_FragmentsOfAsteroid)
    {
        Vector2 posFrag = Vector2(fragment->GetPosition()->GetX(), fragment->GetPosition()->GetY() + kAsteroidVelocity);
        fragment->Move(posFrag);
    }
}



void Asteroid::GenerateContact(GameObject* object)
{
    if(object->Type() == TypeGameObject::Bullet)
    {
        float damage = kHealthLevel;
        GetHealth()->ApplyDamage(damage);
    }
}

TypeGameObject Asteroid::Type()const
{
    return TypeGameObject::Asteroid;
}



void Asteroid::AddFragmentToAsteroid(Asteroid* fragment)
{
    m_FragmentsOfAsteroid.push_back(fragment);
}


AsteroidArray Asteroid::GetFragmentsOfAsteroid()const
{
    return m_FragmentsOfAsteroid;
}

bool Asteroid::IsCollideObject(GameObject* object)
{
    bool isColide = false;
    if(GetHealth()->IsDead())
    {
        for(auto fragment:m_FragmentsOfAsteroid)
        {
            if(fragment->IsCollideObject(object))
            {
                fragment->GenerateContact(object);
            }
        }
        return false;
    }
    if(object->Type() == TypeGameObject::Bullet)
    {

        Vector2 centerAsteroid(GetPosition()->GetX() + GetVertex()->GetRadius(),GetPosition()->GetY() + GetVertex()->GetRadius());
        Vector2 centerBullet(object->GetPosition()->GetX() + object->GetVertex()->GetRadius(),object->GetPosition()->GetY() + object->GetVertex()->GetRadius());
        float distance = Vector2::Distance(centerAsteroid, centerBullet);
        return distance <= GetVertex()->GetRadius() + object->GetVertex()->GetRadius() - 10;
    }
    return isColide;

}

bool Asteroid::IsDrawable()const
{
    
    bool isDraw = GetHealth()->IsDead();
    for(auto fragment:m_FragmentsOfAsteroid)
    {
        isDraw = isDraw && fragment->GetHealth()->IsDead();
    }
    return !isDraw;
}
void Asteroid::SetTexture(Texture* texture)
{
    GameObjectRender::SetTexture(texture);
    for(auto fragment:m_FragmentsOfAsteroid)
    {
        fragment->SetTexture(texture);
    }
}
Asteroid::~Asteroid()
{
    RemoveAllFragmentFromAsteroid();
}

void Asteroid::RemoveFragmentFromAsteroid(Asteroid* fragment)
{
    m_FragmentsOfAsteroid.erase(std::remove(m_FragmentsOfAsteroid.begin(), m_FragmentsOfAsteroid.end(), fragment), m_FragmentsOfAsteroid.end());
}

void Asteroid::RemoveAllFragmentFromAsteroid()
{
    for(AsteroidArray::iterator itr = m_FragmentsOfAsteroid.begin(); itr != m_FragmentsOfAsteroid.end();)
    {
        Asteroid* fragment = *itr;
        delete fragment;
        itr = m_FragmentsOfAsteroid.erase(itr);
    }
}



