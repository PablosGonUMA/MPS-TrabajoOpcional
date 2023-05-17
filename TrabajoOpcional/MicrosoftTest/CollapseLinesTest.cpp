#include "pch.h"
#include "CppUnitTest.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\CollapseLines\CollapseLines.cpp>
#include "../ClasesAProbar/CollapseLines/CollapseLines.h"


using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CollapseLinesTest
{
	TEST_CLASS(CollapseLinesTest)
	{
	public:

		TEST_METHOD(Should_ThrowException_When_InputIsEmptyString)
		{
			Assert::ExpectException<std::out_of_range>([&] { CollapseLines::collapseNewLines(""); });
		}

		TEST_METHOD(Should_ReturnEmptyString_When_InputIsNewLine) {
			string expectedValue = "";
			string actualValue = CollapseLines::collapseNewLines("\n");

			Assert::AreEqual(expectedValue, actualValue);
		}

		TEST_METHOD(Should_ReturnASingleCharacter_When_InputIsASingleCharacter) {
			string expectedValue = "a";
			string actualValue = CollapseLines::collapseNewLines("a");

			Assert::AreEqual(expectedValue, actualValue);
		}

		TEST_METHOD(Should_ReturnASingleCharacter_When_InputIsNewLineFollowedBySingleCharacter) {
			string expectedValue = "a";
			string actualValue = CollapseLines::collapseNewLines("\na");

			Assert::AreEqual(expectedValue, actualValue);
		}

		TEST_METHOD(Should_ReturnEmptyString_When_InputIsTwoNewLines) {
			string expectedValue = "";
			string actualValue = CollapseLines::collapseNewLines("\n\n");

			Assert::AreEqual(expectedValue, actualValue);
		}

		TEST_METHOD(Should_ReturnTheSameString_When_InputIsTwoCharactersFollowedByNewLine) {
			string expectedValue = "aa\n";
			string actualValue = CollapseLines::collapseNewLines("aa\n");

			Assert::AreEqual(expectedValue, actualValue);
		}

		TEST_METHOD(Should_DeleteTheLastNewLine_When_InputIsTwoCharactersFollowedByTwoNewLines) {
			string expectedValue = "aa\n";
			string actualValue = CollapseLines::collapseNewLines("aa\n\n");

			Assert::AreEqual(expectedValue, actualValue);
		}

		TEST_METHOD(Should_DeleteAllNewLines_When_InputIsSingleCharacterFollowedByTwoNewLines) {
			string expectedValue = "a";
			string actualValue = CollapseLines::collapseNewLines("a\n\n");

			Assert::AreEqual(expectedValue, actualValue);
		}
	};
}
