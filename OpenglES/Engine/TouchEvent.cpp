//
//  TouchEvent.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 17.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "TouchEvent.hpp"
using namespace Core;

TouchEvent::TouchEvent(Vector2* pos,Touch type,GameObject* object):m_Object(object),m_Position(pos),m_TouchType(type)
{
    
}

Touch TouchEvent::GetTouchType()const
{
    return m_TouchType;
}

GameObject* TouchEvent::GetObject()const
{
    return m_Object;
}

Vector2* TouchEvent::GetTouchPostion()const
{
    return m_Position;
}

TouchEvent::~TouchEvent()
{
    delete m_Position;
}

