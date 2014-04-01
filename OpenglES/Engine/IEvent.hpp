

#pragma once
#include "GameObject.hpp"
#include "Define.h"
#include "Vector2.hpp"
namespace Core {
    class IEvent
    {
    public:
       virtual Touch GetTouchType()const = 0;
       virtual Vector2* GetTouchPostion()const = 0;
       virtual ~IEvent(){};
    };
}