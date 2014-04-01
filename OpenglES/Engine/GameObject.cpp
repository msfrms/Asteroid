//
//  GameObject.cpp
//  OpenglES
//
//  Created by Admin on 12/06/2013.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "GameObject.hpp"
#include "VertexFactory.hpp"
using namespace Core;

GameObject::GameObject():m_Transform(nullptr),m_Position(new Vector2(0, 0)),m_Health(new Health(kHealthLevel)),m_Vertex(nullptr)
{
    ApplicationProgram* appProgram = ApplicationProgram::ProgramContainer();
    m_ProgramHandle = appProgram->GetActiveProgram();
    
}
GameObject::GameObject(Render::Program* handle):m_ProgramHandle(handle),m_Position(new Vector2(0, 0)),m_Health(new Health(kHealthLevel)),m_Transform(new Transform(handle->GetHandle())),m_Vertex(nullptr)
{
    
}

GameObject::GameObject(Render::Program* handle,VertexObject* vertex):m_ProgramHandle(handle),m_Vertex(vertex),m_Position(new Vector2(0, 0)),
m_Health(new Health(kHealthLevel)),m_Transform(new Transform(handle->GetHandle()))
{
    
}


Vector2* GameObject::GetPosition()const
{
    return m_Position;
}
void GameObject::SetPosition(Vector2* pos)
{
    m_Position->SetPosition(*pos);
}

Transform* GameObject::GetTransform()const
{
    return m_Transform;
}

VertexObject* GameObject::GetVertex()const
{
    return m_Vertex;
}

Render::Program* GameObject::GetProgramHandle()const
{
    return m_ProgramHandle;
}

TypeGameObject GameObject::Type()const
{
    return TypeGameObject::None;
}

Health* GameObject::GetHealth()const
{
    return m_Health;
}

GameObject::~GameObject()
{
    delete m_Position;
    delete m_Health;
    delete m_Transform;
    delete m_Vertex;
}








