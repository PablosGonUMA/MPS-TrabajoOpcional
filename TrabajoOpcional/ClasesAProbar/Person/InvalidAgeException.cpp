#include <iostream>
#include <stdexcept>
#include <string>

#include "InvalidAgeException.h"

InvalidAgeException::InvalidAgeException(const std::string& errorMessage)
    : std::runtime_error(errorMessage) {}
