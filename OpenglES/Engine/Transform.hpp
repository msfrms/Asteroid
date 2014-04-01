
#pragma once
#include "IComponent.hpp"
#include "Vector2.hpp"
#include "Matrix.hpp"
using namespace Math;
namespace Core {
    class Transform : public IComponent
    {
        Matrix* m_Matrix;
        GLuint m_ProgramHandle;
    public:
        Transform(GLuint handle);
        Transform(GLuint handle,Matrix* matrix);
        void Update();
        void SetIdentity();
        void Translate(Vector2 coord);
        void Scale(Vector2 scale);
        ~Transform();
        
    };
}