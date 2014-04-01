//
//  Health.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 19.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Health.hpp"
using namespace Core;

Health::Health(float health):m_Health(health)
{
    
}

void Health::ApplyDamage(float damage)
{
    m_Health -= damage;
}

bool Health::IsDead()const
{
    return m_Health <= 0.f;
}

void Health::AppleHealth(float health)
{
    m_Health += health;
}