

#pragma once
#include "Define.h"
#include "Vector2.hpp"
#include "IGeometry.hpp"
using namespace Math;
using namespace Render;
namespace Core {
    class VertexObject
    {
        FloatVector m_VertextPoints;
        FloatVector m_Color;
        FloatVector m_TexturePoints;
        GLenum m_VertexType;
        GLuint m_VertexCount;
        
        float m_Radius;
    public:
        VertexObject(GLuint vertCount,GLenum vertType);
        VertexObject(GLuint vertCount,GLenum vertType,float radius);
        VertexObject(VectorArray vertCoord,ColorArray colors,VectorArray textCoord);
        void AddVertexPoint(Vector2 coord);
        void AddTexturePoint(Vector2 coord);
        void AddColor(Color color);
        FloatVector GetVertexPoints()const;
        FloatVector GetColor()const;
        FloatVector GetTexturePoints()const;
        GLenum GetVertexType()const;
        GLuint GetVertexCount()const;
        float GetRadius()const;
        ~VertexObject();
    };
}