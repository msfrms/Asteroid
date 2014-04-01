


#pragma once
#include "GameObjectRender.hpp"
#include "Texture.hpp"
#include "Bullet.hpp"
using namespace Core;
typedef std::vector<Render::Bullet*> BulletArray;
namespace Render {
    class Ship: public GameObjectRender
    {
    private:
        BulletArray m_Bullets;
        uint m_ActiveBullets;
        float m_BulletInterval;
        
    public:
        
        Ship(Program* handle);
        Ship(Program* handle,Texture* texture);
        Ship(Program* handle,VertexObject* vertex);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Initialized(uint width,uint height);
        virtual void Move(Vector2 pos);
        void Fire();
        virtual void GenerateContact(GameObject* object);
        virtual bool IsCollideObject(GameObject* object);
        virtual TypeGameObject Type()const;
        void AddBulletToShip(Bullet* bullet);
        BulletArray GetBulletsOfShip()const;
        
        ~Ship();

    };
}

