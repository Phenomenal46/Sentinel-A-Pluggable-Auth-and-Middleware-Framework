#pragma once
#include <string>
#include "Role.h"

class User {
public:
    // Constructor
    User(const std::string& username, const Role& role);

    // Getters
    std::string getUsername() const;
    
    // This is the crucial RBAC method! 
    // The User asks its Role if it has permission.
    bool can(const std::string& permission) const;

private:
    std::string username;
    
    // COMPOSITION: The User "has a" Role. 
    Role userRole; 
};