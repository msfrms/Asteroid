

#pragma once
namespace Render {
    class IGeometry
    {
    public:
       virtual float GetRadius()const = 0;
        ~IGeometry(){};
    };
}
