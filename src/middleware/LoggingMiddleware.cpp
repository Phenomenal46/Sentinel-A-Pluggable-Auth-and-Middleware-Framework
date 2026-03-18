#include "../../include/middleware/LoggingMiddleware.h"

using namespace std;

bool LoggingMiddleware::process(const User& user, const string& requestType) {
    // We just log the action and return true to let the request continue.
    cout << "[LOG] User '" << user.getUsername() << "' is attempting to: " << requestType << endl;
    return true; 
}