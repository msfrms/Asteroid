

#pragma once
#include "RenderEngine.hpp"
#include "ShipRender.hpp"
#include "Asteroid.hpp"
#include "IObserver.hpp"
#include "Bullet.hpp"
#include "GameObjectFactory.hpp"
#include "Options.hpp"
using namespace Factory;
using namespace Core;
using namespace GameOptions;
namespace Render {
    
    class SceneRender: public RenderEngine,public IObserver
    {
    private:
        Ship* m_Ship;
        AsteroidArray m_Asteroids;
        Program* m_ProgramHandle;
        GameObjectFactory* m_AsteroidFactory;
        GameObjectRender* m_BackgroundRender;
        Texture* m_AsteroidTexture;
        Options m_Options;
    public:
        
        SceneRender(Ship* ship,AsteroidArray asteroids,Program* handle,Options options);
        virtual void Initialized(uint width,uint height);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void TouchEvent(IEvent* event);
        virtual bool IsLevelEnd()const;
        virtual void RestartLevel();
        virtual ~SceneRender();
        
    };
}