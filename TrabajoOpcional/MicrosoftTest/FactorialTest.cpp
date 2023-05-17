#include "pch.h"
#include "CppUnitTest.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Factorial\FactorialImpl.cpp>
#include "../ClasesAProbar/Factorial/FactorialImpl.h"
#include "../ClasesAProbar/Factorial/NegativeValueException.h"
#include "../ClasesAProbar/Factorial/ParameterValueCausesOverflow.h"



using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FactorialTest
{
	TEST_CLASS(FactorialTest)
	{
	public:

		TEST_METHOD(Should_ThrowNegativeValueException_When_InputIsNegativeValue)
		{
			FactorialImpl factorial = FactorialImpl();
			Assert::ExpectException<NegativeValueException>([&] { factorial.compute(-1) });
		}

		TEST_METHOD(Should_ReturnEmptyString_When_InputIsNewLine) {
			string expectedValue = "";
			string actualValue = CollapseLines::collapseNewLines("\n");

			Assert::AreEqual(expectedValue, actualValue);
		}


	};
}
