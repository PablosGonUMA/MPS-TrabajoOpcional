#include <iostream>
#include <stdexcept>
#include <string>

#include "NegativeValueException.h"

NegativeValueException::NegativeValueException(const std::string& errorMessage)
    : std::runtime_error(errorMessage) {}