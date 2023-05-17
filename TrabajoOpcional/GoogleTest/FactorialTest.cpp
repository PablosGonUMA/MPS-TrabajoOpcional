#include <../ClasesAProbar/Factorial/Factorial.cpp>

#include <gtest/gtest.h>
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

#include "Factorial.h"
#include "NegativeValueException.h"
#include "ParameterValueCausesOverflow.h"

using namespace std;

// Test fixture for Factorial class
class FactorialTest : public ::testing::Test {
protected:
    Factorial factorial;

    void SetUp() override {
        factorial = Factorial();
    }
};

// Test cases for Factorial::compute() method
TEST_F(FactorialTest, Compute_ValidValues_ReturnsValidResults) {
    EXPECT_EQ(factorial.compute(0), 1);
    EXPECT_EQ(factorial.compute(1), 1);
    EXPECT_EQ(factorial.compute(2), 2);
    EXPECT_EQ(factorial.compute(3), 6);
    EXPECT_EQ(factorial.compute(5), 120);
    EXPECT_EQ(factorial.compute(12), 479001600);
}

TEST_F(FactorialTest, Compute_NegativeValue_ThrowsNegativeValueException) {
    EXPECT_THROW(factorial.compute(-1), NegativeValueException);
}

TEST_F(FactorialTest, Compute_BigValue_ThrowsParameterValueCausesOverflow) {
    EXPECT_THROW(factorial.compute(13), ParameterValueCausesOverflow);
}

// Test cases for Factorial::computeBigValue() method
TEST_F(FactorialTest, ComputeBigValue_ValidValues_ReturnsValidResults) {
    EXPECT_EQ(factorial.computeBigValue(0), BigInteger("1"));
    EXPECT_EQ(factorial.computeBigValue(1), BigInteger("1"));
    EXPECT_EQ(factorial.computeBigValue(2), BigInteger("2"));
    EXPECT_EQ(factorial.computeBigValue(3), BigInteger("6"));
    EXPECT_EQ(factorial.computeBigValue(5), BigInteger("120"));
    EXPECT_EQ(factorial.computeBigValue(12), BigInteger("479001600"));
}

TEST_F(FactorialTest, ComputeBigValue_HighValue_ThrowsParameterValueCausesOverflow) {
    EXPECT_THROW(factorial.computeBigValue(13), ParameterValueCausesOverflow);
    EXPECT_THROW(factorial.computeBigValue(18), ParameterValueCausesOverflow);
}

TEST_F(FactorialTest, ComputeBigValue_NegativeValue_ThrowsNegativeValueException) {
    EXPECT_THROW(factorial.computeBigValue(-1), NegativeValueException);
}
