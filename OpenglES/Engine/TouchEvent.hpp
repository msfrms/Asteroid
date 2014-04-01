
#pragma once
#include "IEvent.hpp"

namespace Core {
    class TouchEvent : public IEvent
    {
    private:
        Vector2* m_Position;
        Touch m_TouchType;
        GameObject* m_Object;
    public:
        TouchEvent(Vector2* pos,Touch type,GameObject* object);
         GameObject* GetObject()const;
         Touch GetTouchType()const;
         Vector2* GetTouchPostion()const;
        ~TouchEvent();
    };
}
