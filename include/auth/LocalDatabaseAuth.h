#pragma once
#include "IAuthProvider.h"
#include <string>
#include <unordered_map>

// Inheritance: LocalDatabaseAuth inherits publicly from IAuthProvider.
class LocalDatabaseAuth : public IAuthProvider
{
public:
    // Constructor: This runs automatically when we create an object of this class.
    LocalDatabaseAuth();

    // Polymorphism: We are overriding the pure virtual function from the interface.
    // The 'override' keyword is a safety net; it tells the compiler to check that
    // we are actually matching a virtual function in the base class.
    bool authenticate(const std::string &username, const std::string &password) override;

private:
    // Encapsulation: We hide the sensitive data.
    // No one outside this class can access 'mockDatabase'.
    // std::unordered_map is a Hash Map that gives us O(1) lookup time!
    std::unordered_map<std::string, std::string> mockDatabase;
};