
#pragma once
#include "Shader.hpp"
#include <map>
#include "IComponent.hpp"
using namespace Core;
namespace Render {
    
    class Program
    {
        
    private:
        GLuint m_Handle;
        ShaderBlock* m_ShaderBlock;
        bool m_IsLinked;
    public:
        Program(ShaderBlock* block);
        void Link();
        ShaderBlock* GetShaderBlock()const;
        
        GLuint GetHandle()const;
        GLuint GetAttribute(string name);
        GLuint GetUniform(string name);
        ~Program();
    };
    
    class ApplicationProgram : public IComponent
    {
    private:
        typedef std::map<TypeShaderBlock, Program*> MapProgram;
        MapProgram m_Programs;
        TypeShaderBlock m_ActiveProgram;
    public:
        static ApplicationProgram* ProgramContainer();
        void AddProgram(Program* program);
        void RemoveProgram(Program* program);
        Program* GetActiveProgram();
        Program* GetProgram(TypeShaderBlock type);
        void Attach(TypeShaderBlock type);
        void Update();
    };
}