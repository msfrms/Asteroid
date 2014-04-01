//
//  Ship.m
//  OpenglES
//
//  Created by Admin on 12/06/2013.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "ShipRender.hpp"
#include "VertexFactory.hpp"


#define KBulletOffset 10
#define kOffsetDuration 2.f
#define kSpaceShipGunX 5
#define kSpaceShipGunY 40

using namespace Render;
using namespace Factory;


Ship::Ship(Program* handle):GameObjectRender(handle)
{
    
}
Ship::Ship(Program* handle,Texture* texture):GameObjectRender(handle)
{
    
}
Ship::Ship(Program* handle,VertexObject* vertex):GameObjectRender(handle,vertex)
{
    
}
void Ship::Initialized(uint width,uint height)
{
    GameObjectRender::Initialized(width, height);
    m_ActiveBullets = 1;
    m_BulletInterval = 0.0f;
    
}

void Ship::Fire()
{
    
    for(uint i = 0; i < m_ActiveBullets; i++)
    {
        auto bullet = m_Bullets[i];
        bullet->Fire();
    }
    
    
}
void Ship::Update(float dt)
{
    GameObjectRender::Update(dt);
    m_BulletInterval += dt;
    //запускаем пули с определенным интервалом
    if(m_BulletInterval >= kOffsetDuration)
    {
        m_ActiveBullets++;
        m_BulletInterval = 0.0f;
    }
    if(m_ActiveBullets > m_Bullets.size())
    {
        m_ActiveBullets = m_Bullets.size();
    }
    //если пуля не летит фиксируем ее на "носу" коробля
    for(auto bullet:m_Bullets)
    {
        bullet->Update(dt);
       
        if(bullet->IsFly())
        {
            bullet->Move(*bullet->GetPosition());
        }
        else
        {
            bullet->Move(Vector2(GetPosition()->GetX() + GetVertex()->GetRadius() - kSpaceShipGunX, GetPosition()->GetY() - GetVertex()->GetRadius()));
        }
        
    }
   
}

void Ship::Draw()
{
    GameObjectRender::Draw();
    for(auto bullet:m_Bullets)
    {
        
        bullet->Draw();
    }
    
}

void Ship::Move(Vector2 pos)
{
    //чтобы при touch шатл был по центру
    Vector2 posCorrected(pos.GetX() - GetVertex()->GetRadius(),pos.GetY() - GetVertex()->GetRadius());
    GameObjectRender::Move(posCorrected);
    for(auto bullet:m_Bullets)
    {
        if(!bullet->IsFly())
        {
            bullet->Move(Vector2(GetPosition()->GetX() + GetVertex()->GetRadius() - kSpaceShipGunX, GetPosition()->GetY() - GetVertex()->GetRadius()));
        }
        
    }
}


void Ship::GenerateContact(GameObject* object)
{
    if(object->Type() == TypeGameObject::Asteroid)
    {
        GetHealth()->ApplyDamage(kHealthLevel);
    }
}

TypeGameObject Ship::Type()const
{
    return TypeGameObject::SpaceShip;
}

BulletArray Ship::GetBulletsOfShip()const
{
    return m_Bullets;
}


void Ship::AddBulletToShip(Bullet* bullet)
{
    bullet->Move(Vector2(GetPosition()->GetX() + GetVertex()->GetRadius() - kSpaceShipGunX, GetPosition()->GetY() - GetVertex()->GetRadius()));
    m_Bullets.push_back(bullet);
}

bool Ship::IsCollideObject(GameObject* object)
{
    bool isCollide = false;
    //если текущий астероид "мертв" пропускаем его коллизии
    if(object->Type() == TypeGameObject::Asteroid)
    {
        if(object->GetHealth()->IsDead())
        {
            return false;
        }
        Vector2 centerShip(GetPosition()->GetX() + GetVertex()->GetRadius(),GetPosition()->GetY() + GetVertex()->GetRadius());
        Vector2 centerAsteroid(object->GetPosition()->GetX() + object->GetVertex()->GetRadius(),object->GetPosition()->GetY() + object->GetVertex()->GetRadius());
        float distance = Vector2::Distance(centerShip, centerAsteroid);
        return distance <= GetVertex()->GetRadius() + object->GetVertex()->GetRadius();
    }
    return isCollide;
}


Ship::~Ship()
{
    for(uint i = 0; i < m_Bullets.size(); i++)
    {
        Bullet* bullet = m_Bullets[i];
        m_Bullets.erase(m_Bullets.begin() + i);
        delete bullet;
    }
}











