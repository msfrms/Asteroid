//
//  Texture.cpp
//  OpenglES
//
//  Created by Radaev Mikhail on 16.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Texture.hpp"
#include <stdlib.h>
using namespace Render;

Texture::Texture(GLuint width,GLuint height,GLuint textureUniform):m_Width(width),m_Height(height),m_TextureUniform(textureUniform)
{
}

GLuint Texture::GetTextureHandle()const
{
    return m_TextureHandle;
}

void Texture::LoadTexture(GLubyte* data)
{
    glGenTextures(1, &m_TextureHandle);
    glBindTexture(GL_TEXTURE_2D, m_TextureHandle);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
}

void Texture::Update()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, m_TextureHandle);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    glUniform1i(m_TextureUniform, 0);
}

Texture::~Texture()
{
    
}


