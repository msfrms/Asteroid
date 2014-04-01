
#pragma once
#include "Vector2.hpp"
#include <OpenGLES/ES2/gl.h>
namespace Math {
    class Matrix
    {
        GLfloat* m_Matrix;
        
    public:
        Matrix();
        Matrix(GLfloat* matrix);
        static void Identity(GLfloat *m);
        GLfloat* GetMat4()const;
        void TranslateBy(Vector2* vector);
        void ScaleBy(Vector2* vector);
        void RotateByX(GLfloat radians);
        void RotateByY(GLfloat radians);
        static void Multiply(GLfloat *m1,GLfloat* m2,GLfloat* out);
        void SetIdentity();
        ~Matrix();
        
    };
}
