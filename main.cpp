#include <iostream>
#include <vector>
#include "include/models/User.h"
#include "include/models/UserFactory.h"
#include "include/models/Role.h"
#include "include/middleware/IMiddleware.h"
#include "include/middleware/LoggingMiddleware.h"
#include "include/middleware/RoleCheckMiddleware.h"

using namespace std;

int main() {
    cout << "--- Sentinel Pipeline Engine ---" << endl;

    // Look how incredibly clean this is now! 
    // The Factory handles all the permission logic internally.
    User alice = UserFactory::createUser("admin_alice", "Admin");
    User bob = UserFactory::createUser("guest_bob", "Guest");

    // 2. Build the Pluggable Middleware Pipeline 
    // We use a vector of Interface pointers so we can mix and match different checkpoints! 
    vector<IMiddleware*> pipeline;
    pipeline.push_back(new LoggingMiddleware());
    pipeline.push_back(new RoleCheckMiddleware());

    // 3. Process a Request! 
    string requestedAction = "DELETE_USERS";
    cout << "\n--- Bob attempts to " << requestedAction << " ---" << endl;
    
    bool requestSuccess = true;
    for (IMiddleware* middleware : pipeline) {
        // If any middleware returns false, the chain breaks!
        if (!middleware->process(bob, requestedAction)) {
            requestSuccess = false;
            break; 
        }
    }

    if (requestSuccess) {
        cout << ">>> ACTION EXECUTED: " << requestedAction << " <<<" << endl;
    } else {
        cout << ">>> ACTION BLOCKED BY PIPELINE <<<" << endl;
    }

    // 4. Memory Cleanup
    for (IMiddleware* middleware : pipeline) {
        delete middleware;
    }

    return 0;
}