//
//  Options.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 03.07.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Options.hpp"
using namespace GameOptions;


Options::Options(DeviceOptions options)
{
    if(options == DeviceOptions::Pad)
    {
        m_BackgroundSize.Width = 1024.f;
        m_BackgroundSize.Height = 768.f;
        m_AsteroidFragmentSize = 50.f;
        m_BulletSize = 25.f;
        m_GameObjectSize = 100.f;
    }
    else
    {
        m_BackgroundSize.Width = 480.f;
        m_BackgroundSize.Height = 320.f;
        m_BulletSize = 12.5f;
        m_GameObjectSize = 50.f;
        m_AsteroidFragmentSize = 25.f;
    }
}
float Options::GetGameObjectSize()const
{
    return m_GameObjectSize;
}

float Options::GetAsteroidFragmentSize()const
{
    return m_AsteroidFragmentSize;
}

float Options::GetBulletSize()const
{
    return m_BulletSize;
}

Size Options::GetBackgroundSize()const
{
    return m_BackgroundSize;
}