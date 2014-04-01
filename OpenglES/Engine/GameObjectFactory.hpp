

#pragma once
#include "Asteroid.hpp"
#include "ShipRender.hpp"
#include "Options.hpp"
using namespace Render;
using namespace GameOptions;
namespace Factory {
    class GameObjectFactory
    {
    private:
        Program* m_ProgramHandle;
        Options m_Options;
    public:
        GameObjectFactory(Program* handle);
        GameObjectFactory(Program* handle,Options options);
        Ship* CreateShip();
        AsteroidArray CreateAsteroids();
        Bullet* CreateBullet();
        ~GameObjectFactory(){};
    };
}
