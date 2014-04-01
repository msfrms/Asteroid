

#pragma once
namespace Core {
    class IComponent
    {
    public:
        virtual void Update() = 0;
        virtual ~IComponent(){};
    };
}