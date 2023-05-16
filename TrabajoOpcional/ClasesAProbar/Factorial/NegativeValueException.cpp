#include <iostream>
#include <stdexcept>
#include <string>

#include "NegativeValueException.h"

namespace Factorial {
    NegativeValueException::NegativeValueException(const std::string& errorMessage)
        : std::runtime_error(errorMessage) {}
}