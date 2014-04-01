//
//  Matrix.m
//  OpenglES
//
//  Created by Admin on 11/06/2013.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Matrix.hpp"
#import <memory.h>
#include <cmath>
using namespace Math;


Matrix::Matrix()
{
    m_Matrix = new GLfloat[16];
    Matrix::Identity(m_Matrix);
}
Matrix::Matrix(GLfloat* matrix):m_Matrix(matrix)
{
   
}

void Matrix::Identity(GLfloat *m)
{
    m[0] = 1.0;
    m[1] = 0.0;
    m[2] = 0.0f;
    m[3] = 0.0f;
    
    m[4] = 0.0;
    m[5] = 1.0;
    m[6] = 0.0f;
    m[7] = 0.0f;
    
    m[8] = 0.0;
    m[9] = 0.0;
    m[10] = 1.0f;
    m[11] = 0.0f;
    
    m[12] = 0.0;
    m[13] = 0.0;
    m[14] = 0.0f;
    m[15] = 1.0f;
}
void Matrix::SetIdentity()
{
    Matrix::Identity(m_Matrix);
}


GLfloat* Matrix::GetMat4()const
{
    return m_Matrix;
}

void Matrix::TranslateBy(Vector2* vector)
{
    GLfloat x = vector->GetX();
    GLfloat y = vector->GetY();
    GLfloat temp[16];
    Matrix::Identity(temp);
    temp[12] = x;
    temp[13] = y;
    temp[14] = 0.0f;
    Matrix::Multiply(temp, m_Matrix,m_Matrix);
}

void Matrix::ScaleBy(Vector2* vector)
{
    GLfloat x = vector->GetX();
    GLfloat y = vector->GetY();
    GLfloat temp[16];
    Matrix::Identity(temp);
    temp[0] = x;
    temp[5] = y;
    temp[10] = 1.0f;
    Matrix::Multiply(temp, m_Matrix,m_Matrix);
}

void Matrix::RotateByX(GLfloat radians)
{
    GLfloat temp[16];
    Matrix::Identity(temp);
    GLfloat c = std::cos(radians);
    GLfloat s = std::sin(radians);
    temp[5] = c;
    temp[6] = s;
    temp[9] = -s;
    temp[10] = c;
    Matrix::Multiply(temp, m_Matrix,m_Matrix);
}

void Matrix::RotateByY(GLfloat radians)
{
    GLfloat temp[16];
    Matrix::Identity(temp);
    GLfloat c = std::cos(radians);
    GLfloat s = std::sin(radians);
    temp[0] = c;
    temp[2] = -s;
    temp[8] = s;
    temp[10] = c;
    Matrix::Multiply(temp, m_Matrix,m_Matrix);
}

void Matrix::Multiply(GLfloat *m1,GLfloat* m2,GLfloat* out)
{
    
    out[0] = m1[0] * m2[0] + m1[4] * m2[1] + m1[8] * m2[2] + m1[12] * m2[3];
	out[1] = m1[1] * m2[0] + m1[5] * m2[1] + m1[9] * m2[2] + m1[13] * m2[3];
	out[2] = m1[2] * m2[0] + m1[6] * m2[1] + m1[10] * m2[2] + m1[14] * m2[3];
	out[3] = m1[3] * m2[0] + m1[7] * m2[1] + m1[11] * m2[2] + m1[15] * m2[3];
	
	out[4] = m1[0] * m2[4] + m1[4] * m2[5] + m1[8] * m2[6] + m1[12] * m2[7];
	out[5] = m1[1] * m2[4] + m1[5] * m2[5] + m1[9] * m2[6] + m1[13] * m2[7];
	out[6] = m1[2] * m2[4] + m1[6] * m2[5] + m1[10] * m2[6] + m1[14] * m2[7];
	out[7] = m1[3] * m2[4] + m1[7] * m2[5] + m1[11] * m2[6] + m1[15] * m2[7];
	
	out[8] = m1[0] * m2[8] + m1[4] * m2[9] + m1[8] * m2[10] + m1[12] * m2[11];
	out[9] = m1[1] * m2[8] + m1[5] * m2[9] + m1[9] * m2[10] + m1[13] * m2[11];
	out[10] = m1[2] * m2[8] + m1[6] * m2[9] + m1[10] * m2[10] + m1[14] * m2[11];
	out[11] = m1[3] * m2[8] + m1[7] * m2[9] + m1[11] * m2[10] + m1[15] * m2[11];
	
	out[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8] * m2[14] + m1[12] * m2[15];
	out[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9] * m2[14] + m1[13] * m2[15];
	out[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];
	out[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];
    
}

Matrix::~Matrix()
{
    delete [] m_Matrix;
}




