


#pragma once
#include <exception>
#include <string>
class Exception: public std::exception {
    
    std::string m_Message;
public:
    Exception(std::string msg);
    const char* what() const throw();
    ~Exception();
};
