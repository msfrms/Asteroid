

#pragma once
#include "Define.h"
#include "IComponent.hpp"
using namespace Core;
namespace Render {
    class Camera : public IComponent
    {
    private:
        uint m_Handle;
        float* m_Ortho;
    public:
        Camera(uint handle);
        void SetupOrtho(uint maxX,uint maxY);
        void SetupOrtho(float left,float right,float bottom,float top,float near,float far);
        void Update();
        ~Camera();
        
    };
}