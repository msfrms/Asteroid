//
//  SceneRender.m
//  OpenglES
//
//  Created by Mikhail Radaev on 14.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "SceneRender.hpp"
#include "VertexFactory.hpp"
#include "Camera.hpp"
#include "Define.h"
#include "Resource.h"
#include "Texture.hpp"

Resource* resource;

using namespace Render;


SceneRender::SceneRender(Ship* ship,AsteroidArray asteroids,Program* handle,Options options):m_Ship(ship),m_Asteroids(asteroids),m_ProgramHandle(handle),m_AsteroidFactory(new GameObjectFactory(handle,options)),m_Options(options)
{
    
}
void SceneRender::Initialized(uint width, uint height)
{
    RenderEngine::Initialized(width, height);
    Camera camera(m_ProgramHandle->GetHandle());
    camera.SetupOrtho(0, width, height, 0, -1., 1.0f);
    
    
    GLuint uniform = m_ProgramHandle->GetUniform("Texture");
    resource = [Resource resource];
    [resource loadImage:@"BackgroundAsteroidBlue_1024x1024"];
    Texture* bgTexture = new Texture(resource.data.size.width,resource.data.size.height,uniform);
    bgTexture->LoadTexture(resource.data.data);
    
    VertexObject* vertBG = VertexFactory::CreateVertexBackground(width,height);
    m_BackgroundRender = new GameObjectRender(m_ProgramHandle, vertBG);
    m_BackgroundRender->Initialized(width, height);
    m_BackgroundRender->SetTexture(bgTexture);
    [resource loadImage:@"ship128"];
    
    Texture* texture = new Texture(resource.data.size.width, resource.data.size.height, uniform);
    texture->LoadTexture(resource.data.data); 
    m_Ship->SetTexture(texture);
    [resource loadImage:@"asteroid_poor"];
    
    m_AsteroidTexture = new Texture(resource.data.size.width,resource.data.size.height,uniform);
    m_AsteroidTexture->LoadTexture(resource.data.data);
    for(auto asteroid:m_Asteroids)
    {
        asteroid->SetTexture(m_AsteroidTexture);
    }
    [resource loadImage:@"Laser"];
    Texture* bulletTexture = new Texture(resource.data.size.width,resource.data.size.height,uniform);
    bulletTexture->LoadTexture(resource.data.data);
    for(auto bullet:m_Ship->GetBulletsOfShip())
    {
        bullet->SetTexture(bulletTexture);
    }
    
}




void SceneRender::Update(float dt)
{
    RenderEngine::Update(dt);
    
    m_Ship->Update(dt);
    m_Ship->Fire();
    if(IsLevelEnd())
    {
        return;
    }
    
    if(m_Asteroids.empty())
    {
        m_Asteroids = m_AsteroidFactory->CreateAsteroids();
        for(auto asteroid:m_Asteroids)
        {
            asteroid->SetTexture(m_AsteroidTexture);
        }

    }
    
    for(uint indexOfAsteroid = 0; indexOfAsteroid < m_Asteroids.size(); indexOfAsteroid++)
    {
        Asteroid* asteroid = m_Asteroids[indexOfAsteroid];
        asteroid->Update(dt);
        if(m_Ship->IsCollideObject(asteroid))
        {
            m_Ship->GenerateContact(asteroid);
        }
        //астероид мертв то определяем коллизи с его осколками
        if(asteroid->GetHealth()->IsDead())
        {
            for(auto fragment:asteroid->GetFragmentsOfAsteroid())
            {
                if(m_Ship->IsCollideObject(fragment))
                {
                    m_Ship->GenerateContact(fragment);
                }
            }

        }
        //если пуля не летит то пропускаем ее
        for(auto bullet:m_Ship->GetBulletsOfShip())
        {
            if(!bullet->IsFly())
            {
                continue;
            }
            if(asteroid->IsCollideObject(bullet))
            {
                asteroid->GenerateContact(bullet);
            }
            
        }
        //если астероид с осколками уничтожен или вышел за границы экрана то уничтожаем его
        if(!asteroid->IsDrawable() || asteroid->GetPosition()->GetY() >= m_Options.GetBackgroundSize().Height)
        {
            m_Asteroids.erase(std::remove(m_Asteroids.begin(), m_Asteroids.end(), asteroid));
            asteroid->RemoveAllFragmentFromAsteroid();
            delete asteroid;
        }
    }
}

void SceneRender::Draw()
{
   
    RenderEngine::Draw();
    m_BackgroundRender->Draw();
    m_Ship->Draw();
    for(auto asteroid:m_Asteroids)
    {
        asteroid->Draw();
    }
}

bool SceneRender::IsLevelEnd()const
{
    return m_Ship->GetHealth()->IsDead();
}

void SceneRender::RestartLevel()
{
    float width = m_Options.GetBackgroundSize().Width;
    float height = m_Options.GetBackgroundSize().Height;
    m_Ship->GetHealth()->AppleHealth(kHealthLevel);
    m_Ship->Move(Vector2(width * 0.5f - m_Ship->GetVertex()->GetRadius() * 2 , height - m_Ship->GetVertex()->GetRadius() * 2));
    if(!m_Asteroids.empty())
    {
        for(AsteroidArray::iterator itr = m_Asteroids.begin(); itr != m_Asteroids.end();)
        {
            Asteroid* asteroid = *itr;
            asteroid->RemoveAllFragmentFromAsteroid();
            itr = m_Asteroids.erase(itr);
            delete asteroid;
        }
    }
}

void SceneRender::TouchEvent(IEvent* event)
{
    Vector2 touchPosition = *event->GetTouchPostion();
    Vector2 shipPosition = *m_Ship->GetPosition();
    float distance = Vector2::Distance(touchPosition, shipPosition);
    if(distance > m_Ship->GetVertex()->GetRadius() * 2)
        return;
    
    m_Ship->Move(*event->GetTouchPostion());
}

SceneRender::~SceneRender()
{
    ApplicationProgram* app = ApplicationProgram::ProgramContainer();
    delete app;
    delete m_Ship;
    delete m_ProgramHandle;
    delete m_AsteroidFactory;
    delete m_AsteroidTexture;
    
}

