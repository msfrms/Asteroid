//
//  Exception.m
//  OpenglES
//
//  Created by Admin on 10/06/2013.
//  Copyright (c) 2013 IDScan. All rights reserved.
//

#include "Exception.hpp"

Exception::Exception(std::string msg):m_Message(msg){}

const char* Exception::what() const throw()
{
    return m_Message.c_str();
}

Exception::~Exception()
{
    
}

