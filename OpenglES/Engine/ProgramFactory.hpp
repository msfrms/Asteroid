


#pragma once
#include "Define.h"
#include "Program.hpp"
using namespace Render;
namespace Factory {
    class ProgramFactory
    {
    public:
        static Program* CreateProgram(TypeShaderBlock type);
    };
}