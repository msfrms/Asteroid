
#define kHealthLevel 1.f
#pragma once
#include "Transform.hpp"
#include "Program.hpp"
#include "Define.h"
#include "Health.hpp"
#include "VertexObject.hpp"
using namespace Math;
namespace Core {
    class GameObject {
    private:
        Vector2* m_Position;
        Transform* m_Transform;
        Health* m_Health;
        Render::Program* m_ProgramHandle;
        VertexObject *m_Vertex;
    public:
        GameObject();
        GameObject(Render::Program* handle);
        GameObject(Render::Program* handle,VertexObject *vertex);
        Vector2* GetPosition()const;
        void SetPosition(Vector2* pos);
        virtual Transform* GetTransform()const;
        virtual VertexObject* GetVertex()const;
        virtual Render::Program* GetProgramHandle()const;
        virtual TypeGameObject Type()const;
        virtual Health* GetHealth()const;
        
        virtual ~GameObject();
        
    };
}
