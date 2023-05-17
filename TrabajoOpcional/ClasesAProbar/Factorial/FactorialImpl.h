#ifndef FACTORIAL_H
#define FACTORIAL_H

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

using namespace std;
class FactorialImpl {
public:
    int compute(int value);
};

#endif
