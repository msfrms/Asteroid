

#include "IEvent.hpp"
namespace Core {
    class IObserver
    {
    public:
        void TouchEvent(IEvent* event);
        virtual ~IObserver(){};
    };
}