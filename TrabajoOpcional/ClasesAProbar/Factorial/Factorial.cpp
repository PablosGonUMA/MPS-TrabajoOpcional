#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iomanip>
#include <sstream>

#include "NegativeValueException.h"
#include "ParameterValueCausesOverflow.h"

namespace Factorial {
    using namespace std;
    class Factorial {
    public:
        int compute(int value) {
            if (value < 0) {
                throw NegativeValueException("The value " + to_string(value) + " is negative");
            }
            if (value > 12) {
                throw ParameterValueCausesOverflow("The value " + to_string(value) + " is too high");
            }

            int result = 1;
            for (int i = 2; i <= value; i++) {
                result *= i;
            }
            return result;
        }

        int64_t computeBigValue(int value) {
            if (value < 0) {
                throw NegativeValueException("The value " + to_string(value) + " is negative");
            }

            int64_t result = 1;
            for (int i = 2; i <= value; i++) {
                result *= i;
            }

            return result;
        }
    };

}
