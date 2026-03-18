#pragma once
#include "../models/User.h"
#include <string>

// The "I" stands for Interface
class IMiddleware {
public:
    virtual ~IMiddleware() {}

    // Every middleware must override this process() method.
    // It returns 'true' if the request should pass to the next checkpoint,
    // and 'false' if the request should be blocked.
    virtual bool process(const User& user, const std::string& requestType) = 0;
};