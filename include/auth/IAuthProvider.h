#pragma once
#include <string>

class IAuthProvider {
public:
    virtual ~IAuthProvider() {}
    
    // The pure virtual function that makes this an Interface
    virtual bool authenticate(const std::string& username, const std::string& password) = 0;
};