

#pragma once
#include "IRenderEngine.hpp"
#include "IMovable.hpp"
#include "Transform.hpp"
#include "Program.hpp"
#include "VertexFactory.hpp"
#include "GameObject.hpp"
#include "Texture.hpp"
#include "ICollision.hpp"
#include "Exception.hpp"
#include "IAnimation.hpp"
using namespace Core;
using namespace Collision;
namespace Render {
    class GameObjectRender : public GameObject, public IRenderEngine,public IMovable,public ICollision
    {
    private:
        GLfloat m_Width,m_Height;
        Texture* m_Texture;
        protected:
        IAnimation* m_Effect;
    public:
        GameObjectRender(Program* handle);
        GameObjectRender(Program* handle,VertexObject* vertex);
        virtual void Initialized(uint width,uint height);
        virtual void Draw();
        virtual void Update(float dt);
        virtual void Move(Vector2 pos);
        virtual void GenerateContact(GameObject* object);
        virtual bool IsCollideObject(GameObject* object);
        virtual void SetTexture(Texture* texture);
        virtual Texture* GetTexture()const;
        virtual bool IsDrawable()const;
        virtual ~GameObjectRender();
        
    };
}