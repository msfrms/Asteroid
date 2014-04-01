//
//  ProgramFactory.cpp
//  OpenglES
//
//  Created by Mikhail Radaev on 30.06.13.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "ProgramFactory.hpp"
#define STRINGIFY(A)  #A
#include "../Shaders/Fragment.frag"
#include "../Shaders/Vertex.vert"
using namespace Factory;

Program* ProgramFactory::CreateProgram(TypeShaderBlock type)
{
    Shader* fragment = nullptr;
    Shader* vertex = nullptr;
    switch (type) {
        case TypeShaderBlock::Textured:
        {
            fragment = new Shader(SimpleFragmentShader,GL_FRAGMENT_SHADER);
            vertex = new Shader(SimpleVertexShader,GL_VERTEX_SHADER);
            
        }break;
            
        default:
            break;
    }
    ShaderBlock* blockShader = new ShaderBlock(vertex,fragment,type);
    Program* program = new Program(blockShader);
    program->Link();
    return program;
}
