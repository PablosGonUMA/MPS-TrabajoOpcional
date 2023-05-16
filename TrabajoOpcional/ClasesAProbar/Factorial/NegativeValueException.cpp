#include <iostream>
#include <stdexcept>
#include <string>

namespace Factorial {
    using namespace std;

    class NegativeValueException : public runtime_error {
    public:
        explicit NegativeValueException(const string& errorMessage)
            : runtime_error(errorMessage) {}
    };
}
