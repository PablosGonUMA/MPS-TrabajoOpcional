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

#include "FactorialImpl.h"
#include "NegativeValueException.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Factorial\NegativeValueException.cpp>
#include "ParameterValueCausesOverflow.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Factorial\ParameterValueCausesOverflow.cpp>

using namespace std;
int FactorialImpl::compute(int value) {
    if (value < 0)
        throw NegativeValueException("The value " + to_string(value) + " is negative");

    if (value > 12)
        throw ParameterValueCausesOverflow("The value " + to_string(value) + " is too high");

    int result = 1;
    for (int i = 2; i <= value; i++) result *= i;

    return result;
}
