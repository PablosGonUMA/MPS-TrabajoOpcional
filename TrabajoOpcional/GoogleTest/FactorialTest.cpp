#include "pch.h"
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
#include <tuple>

#include "../ClasesAProbar/Factorial/FactorialImpl.h"
#include <C:\Users\Dani\OneDrive\Documentos\Uni\3o\Mantenimiento\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Factorial\FactorialImpl.cpp>
#include "../ClasesAProbar/Factorial/NegativeValueException.h"
#include "../ClasesAProbar/Factorial/ParameterValueCausesOverflow.h"

using namespace std;

namespace FactorialTestsForCompute {
    // Test class of individual tests for the Factorial class
    class FactorialTest : public ::testing::Test {
    protected:
        void SetUp() override {
            FactorialImpl factorial;
            factorial = FactorialImpl();
        }
    };

    TEST(FactorialTest, Compute_negative_value_throws_NegativeValueException) {
        FactorialImpl factorial = FactorialImpl();
        EXPECT_THROW(factorial.compute(-1), NegativeValueException);
    }

    TEST(FactorialTest, Compute_big_value_throws_ParameterValueCausesOverflow) {
        FactorialImpl factorial = FactorialImpl();
        EXPECT_THROW(factorial.compute(13), ParameterValueCausesOverflow);
    }

    // Test class of parametrized tests for the Factorial class
    class ParametrizedFactorialTest : public ::testing::TestWithParam<tuple<int, int>> {
    protected:
        void SetUp() override {
            FactorialImpl factorial;
            factorial = FactorialImpl();
        }
    };

    TEST_P(ParametrizedFactorialTest, Compute_valid_values_returns_valid_results) {
        FactorialImpl factorial = FactorialImpl();
        int numberToCompute, expected;
        tie(numberToCompute, expected) = GetParam();
        EXPECT_EQ(factorial.compute(numberToCompute), expected);
    }

    // Values for parametrized test class ParametrizedFactorialTest
    INSTANTIATE_TEST_CASE_P(ParametrizedFactorialTestValues, ParametrizedFactorialTest,
        ::testing::Values(make_tuple(0,1), make_tuple(1,1), make_tuple(2,2), 
            make_tuple(3,6), make_tuple(5,120), make_tuple(12,479001600)));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
