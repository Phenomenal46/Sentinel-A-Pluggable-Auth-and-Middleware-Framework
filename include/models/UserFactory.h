#pragma once
#include "User.h"
#include <string>

class UserFactory {
public:
    // A 'static' method means we don't have to create a UserFactory object 
    // to use this tool. We can just call UserFactory::createUser() directly!
    static User createUser(const std::string& username, const std::string& roleType);
};