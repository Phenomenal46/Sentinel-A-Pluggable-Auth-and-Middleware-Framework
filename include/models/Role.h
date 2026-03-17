#pragma once
#include <string>
#include <unordered_set>

class Role {
public:
    // Constructor to give the role a name (e.g., "Admin", "Guest")
    Role(const std::string& roleName);

    // Method to grant a new permission to this role
    void addPermission(const std::string& permission);

    // Method to check if this role has a specific permission
    bool hasPermission(const std::string& permission) const;

    // Getter for the role name
    std::string getName() const;

private:
    std::string name;
    
    // Encapsulation: The outside world cannot mess with this list directly.
    // std::unordered_set provides O(1) time complexity for finding items!
    std::unordered_set<std::string> permissions;
};