

#pragma once
#include <OpenGLES/ES2/gl.h>
namespace Math {
    class Vector2
    {
    private:
        GLfloat m_X;
        GLfloat m_Y;
    public:
        GLfloat GetX()const;
        GLfloat GetY()const;
        static float Distance(Vector2 pos1,Vector2 pos2);
        void SetPosition(Vector2 pos);
        Vector2(GLfloat x,GLfloat y);
        bool operator ==(const Vector2& vec3);
        ~Vector2(){}
    };
}
