#include "../../include/models/User.h"

using namespace std;

User::User(const string& username, const Role& role) : username(username), userRole(role) {
    // This is an "initializer list" - a highly efficient way to set variables in C++ constructors.
}

string User::getUsername() const {
    return username;
}

// The User delegates the permission check to its Role object
bool User::can(const string& permission) const {
    return userRole.hasPermission(permission);
}