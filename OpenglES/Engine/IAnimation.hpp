

#pragma once
namespace Render {
    class IAnimation
    {
    public:
       virtual void Animate() = 0;
       virtual ~IAnimation(){};
    };
}
