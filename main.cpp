#include <iostream>
#include "include/auth/LocalDatabaseAuth.h"
#include "include/models/User.h"
#include "include/models/Role.h"

using namespace std;

int main() {
    cout << "--- Sentinel RBAC Engine ---" << endl;

    // 1. Create our Roles and assign Permissions
    Role adminRole("Administrator");
    adminRole.addPermission("READ_FILES");
    adminRole.addPermission("DELETE_USERS");
    adminRole.addPermission("SHUTDOWN_SERVER");

    Role internRole("Intern");
    internRole.addPermission("READ_FILES");
    // Interns CANNOT delete users or shutdown servers!

    // 2. Create Users using COMPOSITION (Giving them a Role)
    User alice("admin_alice", adminRole);
    User bob("intern_bob", internRole);

    // 3. Test our O(1) Permission System
    cout << "\n[Checking Permissions for Alice (" << alice.getUsername() << ")]" << endl;
    if (alice.can("DELETE_USERS")) {
        cout << "SUCCESS: Alice can delete users." << endl;
    }

    cout << "\n[Checking Permissions for Bob (" << bob.getUsername() << ")]" << endl;
    if (bob.can("DELETE_USERS")) {
        cout << "SUCCESS: Bob can delete users." << endl;
    } else {
        cout << "ACCESS DENIED: Bob does not have permission to delete users." << endl;
    }

    return 0;
}