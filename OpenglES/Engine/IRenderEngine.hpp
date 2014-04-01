

#pragma once
#include "Define.h"
namespace Render {
    class IRenderEngine {
    public:
        virtual void Initialized(uint width,uint height) = 0;
        virtual void Draw() = 0;
        virtual void Update(float dt) = 0;
        virtual ~IRenderEngine(){};
    };
}

