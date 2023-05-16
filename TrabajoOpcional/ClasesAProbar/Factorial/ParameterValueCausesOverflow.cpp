#include <iostream>
#include <stdexcept>
#include <string>

namespace Factorial {
    using namespace std;

    class ParameterValueCausesOverflow : public runtime_error {
    public:
        explicit ParameterValueCausesOverflow(const string& errorMessage)
            : runtime_error(errorMessage) {}
    };
}