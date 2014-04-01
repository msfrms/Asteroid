


#pragma once
#include <OpenGLES/ES2/gl.h>
#include "IComponent.hpp"
namespace Render {
    class Texture : public Core::IComponent
    {
    private:
        GLuint m_TextureHandle;
        GLuint m_Width;
        GLuint m_Height;
        GLuint m_TextureUniform;
    public:
        Texture(GLuint width,GLuint height,GLuint textureUniform);
        void LoadTexture(GLubyte* data);
        GLuint GetTextureHandle()const;
        void Update();
        ~Texture();
    };
}
