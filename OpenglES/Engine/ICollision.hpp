

#pragma once
#include "GameObject.hpp"
using namespace Core;
namespace Collision
{
    class ICollision
    {
    public:
        virtual void GenerateContact(GameObject* object) = 0;
        virtual bool IsCollideObject(GameObject* object) = 0;
        virtual ~ICollision(){};
    };
}