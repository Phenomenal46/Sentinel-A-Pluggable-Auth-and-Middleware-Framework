#include "../../include/models/Role.h"

using namespace std;

// Constructor sets the name
Role::Role(const string& roleName) {
    name = roleName;
}

// Adds a permission to our set
void Role::addPermission(const string& permission) {
    permissions.insert(permission);
}

// Checks if a permission exists in the set
bool Role::hasPermission(const string& permission) const {
    // .find() looks through the unordered_set. 
    // If it reaches .end(), it means the permission wasn't found.
    // Because it's an unordered_set, this lookup happens instantly (O(1)).
    return permissions.find(permission) != permissions.end();
}

string Role::getName() const {
    return name;
}