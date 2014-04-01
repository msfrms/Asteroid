
#pragma once
#include "IRenderEngine.hpp"
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "GameObject.hpp"
#include "Texture.hpp"
namespace Render {
    class RenderEngine :public GameObject, public IRenderEngine
    {
    protected:
        Texture* m_Texture;
    private:
        GLuint m_frameBuffer;
        GLuint m_renderBuffer;
        GLuint m_programContext;
        GLuint m_frameBufferMSAA;
    public:
        RenderEngine();
        void Initialized(uint width,uint height);
        void Draw();
        void Update(float dt);
        ~RenderEngine();
    };
}
