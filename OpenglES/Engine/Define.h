
#pragma once
#include <vector>
#include "Vector2.hpp"
#include <iostream>

#define NSLog(log) std::cout << log << std::endl
enum class DeviceOptions {Pad,Phone};
enum class Touch {TouchBegin,TouchEnd,TouchMoved,TouchCacel};
enum class TypeGameObject {SpaceShip,Bullet,Asteroid,None};
enum class TypeShader {ShaderFragment,ShaderVertex};
enum class TypeShaderBlock {Textured};
typedef unsigned int uint;
typedef std::vector<GLfloat> FloatVector;
typedef std::vector<Math::Vector2> VectorArray;
struct Color;
typedef std::vector<Color> ColorArray;


struct Color
{
    float r;
    float g;
    float b;
    float a;
    Color(float red,float green,float blue,float alpha)
    {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
};

