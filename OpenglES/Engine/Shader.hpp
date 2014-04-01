

#pragma once
#include <string>
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>
#include "Define.h"
#include <map>
using namespace std;
namespace Render {
    class Shader
    {
    private:
        const GLuint m_ShaderHandle;
        bool m_IsCompiled;
       
    public:
        Shader(string source,GLenum type);
        void Compile();
        bool IsCompiled()const;
        GLuint GetHandle()const;
        ~Shader();
    };
    
    class ShaderBlock
    {
    private:
        typedef std::map<TypeShader,Shader*> ShaderMap;
        ShaderMap m_Shaders;
        TypeShaderBlock m_Type;
    public:
        ShaderBlock(Shader* vertex,Shader* fragment,TypeShaderBlock type);
        Shader* GetShader(TypeShader type);
        TypeShaderBlock GetType()const;
        ~ShaderBlock();
    };
}
