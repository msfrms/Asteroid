

#pragma once
#include "Vector2.hpp"
using namespace Math;
namespace Core {
    class IMovable
    {
    public:
        void Move(Vector2 pos);
        virtual ~IMovable(){};
    };
}