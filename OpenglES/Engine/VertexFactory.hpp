
#pragma once
#include "Define.h"
#include <OpenGLES/ES2/gl.h>
#include <vector>
#include "Vector2.hpp"
#include "VertexObject.hpp"
using namespace Core;
namespace Factory {
    class VertexFactory
    {
    public:
        static VertexObject* CreateVertexObject(float size = 100.f);
        static VertexObject* CreateFragmentOfAsteroid(float size = 50.f);
        static VertexObject* CreateVertexBullet(float size = 25.f);
        static VertexObject* CreateVertexBackground(float width = 1024.f,float height = 768.f);
    };
}