#include <iostream>
#include <stdexcept>
#include <string>

#include "InvalidGenderException.h"

InvalidGenderException::InvalidGenderException(const std::string& errorMessage)
    : std::runtime_error(errorMessage) {}
