

#include "GameObjectFactory.hpp"
#include "Utils.hpp"
#define kBulletCount 10
#define kMaxAsteroidCount 5
#define kMaxAsteroidCountAtLine 5
#define kMaxFragmentOfAsteroidCount 3
using namespace Factory;
using namespace Random;
GameObjectFactory::GameObjectFactory(Program* handle):m_ProgramHandle(handle),m_Options(DeviceOptions::Pad)
{
    
}

GameObjectFactory::GameObjectFactory(Program* handle,Options options):m_Options(options),m_ProgramHandle(handle)
{
    
}


Ship* GameObjectFactory::CreateShip()
{
    uint width = m_Options.GetBackgroundSize().Width;
    uint height = m_Options.GetBackgroundSize().Height;
    VertexObject *obj = VertexFactory::CreateVertexObject(m_Options.GetGameObjectSize());
    Ship *ship = new Ship(m_ProgramHandle,obj);
    ship->Initialized(width, height);
    
    ship->Move(Vector2(width * 0.5f - ship->GetVertex()->GetRadius() , height - ship->GetVertex()->GetRadius() * 2.f));
    
    for(uint index = 0; index < kBulletCount; index++)
    {
        VertexObject* vertBullet = VertexFactory::CreateVertexBullet(m_Options.GetBulletSize());
        Bullet* bullet = new Bullet(m_ProgramHandle,vertBullet);
        bullet->Initialized(width, height);
        ship->AddBulletToShip(bullet);
    }
    return ship;
}




AsteroidArray GameObjectFactory::CreateAsteroids()
{
    float offsetX =  0.f;
    float offsetY = 0;
    uint width = m_Options.GetBackgroundSize().Width;
    uint height = m_Options.GetBackgroundSize().Height;
    AsteroidArray asteroids;
    uint countLineOfAsteroid = kMaxAsteroidCountAtLine;
    for(uint indexOfAsteroid = 0; indexOfAsteroid < kMaxAsteroidCount; indexOfAsteroid++)
    {
        VertexObject* vertex = VertexFactory::CreateVertexObject(m_Options.GetGameObjectSize());
        Asteroid* asteroid = new Asteroid(m_ProgramHandle,vertex);
        asteroid->Initialized(width, height);
        asteroid->Move(Vector2(offsetX, offsetY));
        
        offsetX += asteroid->GetVertex()->GetRadius() * 3;
        if(indexOfAsteroid % countLineOfAsteroid == 0)
        {
            offsetY += asteroid->GetVertex()->GetRadius() * 2;
            offsetX = asteroid->GetVertex()->GetRadius();
            countLineOfAsteroid = kMaxAsteroidCountAtLine;
        }
        uint countFragmentOfAsteroid = kMaxFragmentOfAsteroidCount;
        for(uint indexOfFragment = 0; indexOfFragment < countFragmentOfAsteroid; indexOfFragment++)
        {
            VertexObject* vertexOfFragment = VertexFactory::CreateFragmentOfAsteroid(m_Options.GetAsteroidFragmentSize());
            Asteroid* fragment = new Asteroid(m_ProgramHandle,vertexOfFragment);
            fragment->Initialized(width, height);
            Vector2 posAsteroid = *asteroid->GetPosition();
            Vector2 center = Vector2(posAsteroid.GetX() + asteroid->GetVertex()->GetRadius(), posAsteroid.GetY() - asteroid->GetVertex()->GetRadius());
            float x = Utils<float>::GenerateRandomRealValue(posAsteroid.GetX(), center.GetX() * 1.3);
            float y = Utils<float>::GenerateRandomRealValue(center.GetY(), center.GetY() * 1.5);
            fragment->Move(Vector2(x, y));
            asteroid->AddFragmentToAsteroid(fragment);

        }
        asteroids.push_back(asteroid);
        
    }
    return asteroids;

}

