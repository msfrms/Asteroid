

#pragma once
#include "Define.h"
namespace GameOptions {
    struct Size
    {
        float Width;
        float Height;
    };
    class Options
    {
    private:
        float m_GameObjectSize;
        float m_AsteroidFragmentSize;
        float m_BulletSize;
        Size m_BackgroundSize;
    public:
        Options(DeviceOptions options);
        virtual float GetGameObjectSize()const;
        virtual float GetAsteroidFragmentSize()const;
        virtual float GetBulletSize()const;
        virtual Size GetBackgroundSize()const;
    };
}