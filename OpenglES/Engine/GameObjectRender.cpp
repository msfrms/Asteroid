//
//  GameObjectRender.cpp
//  OpenglES
//
//  Created by Radaev Mikhail on 15.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "GameObjectRender.hpp"




using namespace Render;

GameObjectRender::GameObjectRender(Program* handle):GameObject(handle),m_Effect(nullptr),m_Texture(nullptr)
{
    
}

GameObjectRender::GameObjectRender(Program* handle,VertexObject* vertex):GameObject(handle,vertex),m_Effect(nullptr),m_Texture(nullptr)
{
    
}

void GameObjectRender::Initialized(uint width,uint height)
{
    m_Width = width;
    m_Height = height;
}

void GameObjectRender::Update(float dt)
{
    
}
void GameObjectRender::SetTexture(Texture* texture)
{
    if(m_Texture != nullptr)
    {
        delete m_Texture;
        m_Texture = nullptr;
    }
    m_Texture = texture;
}
Texture* GameObjectRender::GetTexture()const
{
    return m_Texture;
}

void GameObjectRender::Draw()
{
    
    if(GetHealth()->IsDead())
    {
        if(m_Effect != nullptr)
        {
            m_Effect->Animate();
        }
        return;
    }
    GetTransform()->Update();
    
    if(GetTexture() != nullptr)
    {
        GetTexture()->Update();
    }
    
    GLuint positionSlot = GetProgramHandle()->GetAttribute("Position");
    GLuint colorSlot = GetProgramHandle()->GetAttribute("SourceColor");
    GLuint textureSlot = GetProgramHandle()->GetAttribute("TexCoordIn");
    glEnableVertexAttribArray(positionSlot);
    glEnableVertexAttribArray(colorSlot);
    glEnableVertexAttribArray(textureSlot);
    GLsizei stride = 0;
    VertexObject *vertexObject = GetVertex();
   
    FloatVector vertPoints = vertexObject->GetVertexPoints();
    FloatVector textPoints = vertexObject->GetTexturePoints();
    FloatVector colors = vertexObject->GetColor();
    const GLvoid* pCoords = &vertPoints[0];
    const GLvoid* pColors = &colors[0];
    const GLvoid* pTexture = &textPoints[0];
    glVertexAttribPointer(positionSlot, 2, GL_FLOAT, GL_FALSE, stride, pCoords);
    glVertexAttribPointer(colorSlot, 4, GL_FLOAT, GL_FALSE, stride, pColors);
    glVertexAttribPointer(textureSlot, 2, GL_FLOAT, GL_FALSE, stride,pTexture);
    
    glDrawArrays(vertexObject->GetVertexType(), 0, vertexObject->GetVertexCount());
    
    glDisableVertexAttribArray(positionSlot);
    glDisableVertexAttribArray(colorSlot);
    glDisableVertexAttribArray(textureSlot);
    
}

void GameObjectRender::Move(Vector2 pos)
{
    GetPosition()->SetPosition(pos);
    GetTransform()->SetIdentity();
    GetTransform()->Translate(pos);
}
void GameObjectRender::GenerateContact(GameObject* object)
{
    throw Exception("void GameObjectRender::GenerateContact(GameObject* object) not Realized");
}

bool GameObjectRender::IsCollideObject(GameObject* object)
{
    return false;
}

bool GameObjectRender::IsDrawable()const
{
    return !GetHealth()->IsDead();
}


GameObjectRender::~GameObjectRender()
{
}



