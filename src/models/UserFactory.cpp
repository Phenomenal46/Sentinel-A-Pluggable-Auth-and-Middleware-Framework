#include "../../include/models/UserFactory.h"
#include "../../include/models/Role.h"
#include <stdexcept>

using namespace std;

User UserFactory::createUser(const string& username, const string& roleType) {
    // If the system requests an Admin...
    if (roleType == "Admin") {
        Role adminRole("Administrator");
        adminRole.addPermission("READ_FILES");
        adminRole.addPermission("DELETE_USERS");
        adminRole.addPermission("SHUTDOWN_SERVER");
        return User(username, adminRole);
    } 
    // If the system requests a Guest...
    else if (roleType == "Guest") {
        Role guestRole("Guest");
        guestRole.addPermission("READ_FILES");
        // Guests get no destructive permissions!
        return User(username, guestRole);
    }
    // Professional error handling: What if someone asks for a role that doesn't exist?
    else {
        throw invalid_argument("Error: Unknown role type requested from Factory.");
    }
}