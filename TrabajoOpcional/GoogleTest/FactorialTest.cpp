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

#include "../ClasesAProbar/Factorial/FactorialImpl.h"
#include <C:\Users\Dani\OneDrive\Documentos\Uni\3o\Mantenimiento\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Factorial\FactorialImpl.cpp>
#include "../ClasesAProbar/Factorial/NegativeValueException.h"
#include "../ClasesAProbar/Factorial/ParameterValueCausesOverflow.h"

using namespace std;

namespace FactorialTests {
    // Test fixture for Factorial class
    class FactorialTest : public ::testing::Test {
    protected:
        void SetUp() override {
            FactorialImpl factorial;
            factorial = FactorialImpl();
        }
    };


    // Test cases for Factorial::compute() method
    TEST(FactorialTest, Compute_ValidValues_ReturnsValidResults) {
        FactorialImpl factorial = FactorialImpl();
        EXPECT_EQ(factorial.compute(0), 1);
        EXPECT_EQ(factorial.compute(1), 1);
        EXPECT_EQ(factorial.compute(2), 2);
        EXPECT_EQ(factorial.compute(3), 6);
        EXPECT_EQ(factorial.compute(5), 120);
        EXPECT_EQ(factorial.compute(12), 479001600);
    }

    TEST(FactorialTest, Compute_NegativeValue_ThrowsNegativeValueException) {
        FactorialImpl factorial = FactorialImpl();
        EXPECT_THROW(factorial.compute(-1), NegativeValueException);
    }

    TEST(FactorialTest, Compute_BigValue_ThrowsParameterValueCausesOverflow) {
        FactorialImpl factorial = FactorialImpl();
        EXPECT_THROW(factorial.compute(13), ParameterValueCausesOverflow);
    }
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
