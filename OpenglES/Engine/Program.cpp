//
//  Program.m
//  OpenglES
//
//  Created by Admin on 10/06/2013.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Program.hpp"
#include "Exception.hpp"
using namespace Render;

Program::Program(ShaderBlock* block):m_Handle(glCreateProgram()),m_ShaderBlock(block),m_IsLinked(false)
{
}

ShaderBlock* Program::GetShaderBlock()const
{
    return m_ShaderBlock;
}


void Program::Link()
{
    if(m_IsLinked)
    {
        return;
    }
    Shader *shaderFragment = m_ShaderBlock->GetShader(TypeShader::ShaderFragment);
    Shader *shaderVertex = m_ShaderBlock->GetShader(TypeShader::ShaderVertex);
    if(!shaderFragment->IsCompiled())
    {
        shaderFragment->Compile();
        glAttachShader(m_Handle, shaderFragment->GetHandle());
        
    }
    if(!shaderVertex->IsCompiled())
    {
        shaderVertex->Compile();
        glAttachShader(m_Handle, shaderVertex->GetHandle());
    }
    glLinkProgram(m_Handle);
    m_IsLinked = true;
    GLint success;
    glGetProgramiv(m_Handle, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        GLchar messages[256];
        glGetProgramInfoLog(m_Handle, sizeof(messages), 0, &messages[0]);
        m_IsLinked = false;
        throw Exception(messages);
    }

}
GLuint Program::GetHandle()const
{
    return m_Handle;
}
GLuint Program::GetAttribute(string name)
{
    return glGetAttribLocation(m_Handle, name.c_str());
}
GLuint Program::GetUniform(string name)
{
    return glGetUniformLocation(m_Handle, name.c_str());
}

Program::~Program()
{
}
static ApplicationProgram* AppProgram = nullptr;
ApplicationProgram* ApplicationProgram::ProgramContainer()
{
    if(AppProgram == nullptr)
    {
        AppProgram = new ApplicationProgram();
    }
    return AppProgram;
}
void ApplicationProgram::AddProgram(Program* program)
{
    ShaderBlock* block = program->GetShaderBlock();
    m_Programs[block->GetType()] = program;
}
void ApplicationProgram::RemoveProgram(Program* program)
{
    ShaderBlock* block = program->GetShaderBlock();
    m_Programs.erase(block->GetType());
}
void ApplicationProgram::Attach(TypeShaderBlock type)
{
    m_ActiveProgram = type;
}
Program* ApplicationProgram::GetActiveProgram()
{
    return m_Programs[m_ActiveProgram];
}
Program* ApplicationProgram::GetProgram(TypeShaderBlock type)
{
    return m_Programs[type];
}
void ApplicationProgram::Update()
{
    Program* activeProgram = m_Programs[m_ActiveProgram];
    glUseProgram(activeProgram->GetHandle());
}


