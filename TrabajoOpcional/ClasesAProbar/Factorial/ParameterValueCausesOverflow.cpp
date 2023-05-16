#include <iostream>
#include <stdexcept>
#include <string>

#include "ParameterValueCausesOverflow.h"

namespace Factorial {
    ParameterValueCausesOverflow::ParameterValueCausesOverflow(const std::string& errorMessage)
        : std::runtime_error(errorMessage) {}
}
