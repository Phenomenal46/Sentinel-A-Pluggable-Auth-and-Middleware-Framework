#pragma once
#include "IMiddleware.h"
#include <iostream>

class LoggingMiddleware : public IMiddleware {
public:
    bool process(const User& user, const std::string& requestType) override;
};