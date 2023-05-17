#include "pch.h"
#include "CppUnitTest.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\CollapseLines\CollapseLines.cpp>
#include "../ClasesAProbar/CollapseLines/CollapseLines.h"


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MicrosoftTest
{
	TEST_CLASS(MicrosoftTest)
	{
	public:
		
		TEST_METHOD(Should_ThrowException_When_InputIsEmptyString)
		{
			Assert::ExpectException<std::out_of_range>([&] { CollapseLines::collapseNewLines(""); });
		}
	};
}
