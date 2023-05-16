#ifndef PARAMETERVALUECAUSESOVERFLOW_H
#define PARAMETERVALUECAUSESOVERFLOW_H

#include <stdexcept>
#include <string>

namespace Factorial {
    class ParameterValueCausesOverflow : public std::runtime_error {
    public:
        explicit ParameterValueCausesOverflow(const std::string& errorMessage);
    };
}

#endif
