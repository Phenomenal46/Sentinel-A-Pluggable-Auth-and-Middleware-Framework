#include "../../include/auth/LocalDatabaseAuth.h"
#include <iostream>

// we use this ONLY in the .cpp file to keep our headers clean!
using namespace std;

// 1. Implementing the Constructor
LocalDatabaseAuth::LocalDatabaseAuth() {
    // Let's populate our private mock database with some dummy users.
    // In a real application, these would be securely hashed passwords.
    // Key = Username, Value = Password
    mockDatabase["admin_alice"] = "SuperSecret123";
    mockDatabase["intern_bob"]  = "password123";
}

// 2. Implementing the Authentication Logic
bool LocalDatabaseAuth::authenticate(const string& username, const string& password) {
    // Step A: Search for the username in our Hash Map
    // 'find()' looks for the key. If it doesn't find it, it returns an iterator pointing to 'end()'.
    auto it = mockDatabase.find(username);

    // Step B: If the user exists
    if (it != mockDatabase.end()) {
        // 'it->second' accesses the Value (the password) associated with the Key (the username).
        if (it->second == password) {
            cout << "[Auth Log] User '" << username << "' authenticated successfully." << endl;
            return true; // Passwords match!
        } else {
            cout << "[Auth Log] Invalid password for user '" << username << "'." << endl;
            return false; // Passwords do not match
        }
    }

    // Step C: If the user does not exist in the map
    cout << "[Auth Log] User '" << username << "' not found." << endl;
    return false;
}