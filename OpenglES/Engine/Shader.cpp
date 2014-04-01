//
//  Shader.m
//  OpenglES
//
//  Created by Mikhail Radaev on 10.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Shader.hpp"
#include "Exception.hpp"
using namespace Render;

Shader::Shader(string source,GLenum type):m_ShaderHandle(glCreateShader(type)),m_IsCompiled(false)
{
    const char* src = source.c_str();
    glShaderSource(m_ShaderHandle, 1, &src, 0);
   
}
void Shader::Compile()
{
    m_IsCompiled = true;
    glCompileShader(m_ShaderHandle);
    GLint success;
    glGetShaderiv(m_ShaderHandle, GL_COMPILE_STATUS, &success);
    if(success == GL_FALSE)
    {
        char message[256];
        glGetShaderInfoLog(m_ShaderHandle, sizeof(message), 0, &message[0]);
        throw Exception(message);
    }
}
GLuint Shader::GetHandle()const
{
    return m_ShaderHandle;
}

bool Shader::IsCompiled()const
{
    return m_IsCompiled;
}



Shader::~Shader()
{
    
}
ShaderBlock::ShaderBlock(Shader* vertex,Shader* fragment,TypeShaderBlock type):m_Type(type)
{
    m_Shaders[TypeShader::ShaderFragment] = fragment;
    m_Shaders[TypeShader::ShaderVertex] = vertex;
    
}
Shader* ShaderBlock::GetShader(TypeShader type)
{
    return m_Shaders[type];
}

TypeShaderBlock ShaderBlock::GetType()const
{
    return m_Type;
}
ShaderBlock::~ShaderBlock()
{
    m_Shaders.erase(m_Shaders.begin(), m_Shaders.end());
}









 
