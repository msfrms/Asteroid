
#pragma once
#include "GameObjectRender.hpp"
#include "IGeometry.hpp"
namespace Render {
    class Bullet: public GameObjectRender, public IGeometry
    {
    private:
        bool m_IsFly;
        float m_Radius;
    public:
        Bullet(Program* handle);
        Bullet(Program* handle,VertexObject* vertex);
        void Draw();
        void Update(float dt);
        void Initialized(uint width,uint height);
        void Fire();
        bool IsFly() const;        
        virtual void GenerateContact(GameObject* object);
        virtual bool IsCollideObject(GameObject* object);
        virtual TypeGameObject Type()const;
        
        virtual float GetRadius()const;
        virtual ~Bullet();
        

    };
}