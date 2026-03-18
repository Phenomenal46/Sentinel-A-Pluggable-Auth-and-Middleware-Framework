#include "../../include/middleware/RoleCheckMiddleware.h"

using namespace std;

bool RoleCheckMiddleware::process(const User& user, const string& requestType) {
    // We check if the user has the exact permission matching the requestType
    if (user.can(requestType)) {
        cout << "[SECURITY] Access Granted for: " << requestType << endl;
        return true; // Let them pass!
    } else {
        cout << "[SECURITY] ACCESS DENIED. Missing permission: " << requestType << endl;
        return false; // Block the request!
    }
}