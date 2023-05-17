#include "pch.h"
#include <gtest/gtest.h>

#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\CollapseLines\CollapseLines.cpp>

using namespace std;
using namespace testing;

class CollapseLinesTest : public ::testing::Test {};

TEST(CollapseLinesTest, Should_ThrowException_When_InputIsEmptyString) {
    EXPECT_THROW(CollapseLines::collapseNewLines(""), std::out_of_range);
}

TEST(CollapseLinesTest, Should_ReturnEmptyString_When_InputIsNewLine){

    string expectedValue = "";
    string actualValue = CollapseLines::collapseNewLines("\n");

    EXPECT_EQ(expectedValue, actualValue);
}

TEST(CollapseLinesTest, Should_ReturnASingleCharacter_When_InputIsASingleCharacter){

    string expectedValue = "a";
    string actualValue = CollapseLines::collapseNewLines("a");

    EXPECT_EQ(expectedValue, actualValue);
}

TEST(CollapseLinesTest, Should_ReturnASingleCharacter_When_InputIsNewLineFollowedBySingleCharacter){

    string expectedValue = "a";
    string actualValue = CollapseLines::collapseNewLines("\na");

    EXPECT_EQ(expectedValue, actualValue);
}

TEST(CollapseLinesTest, Should_ReturnEmptyString_When_InputIsTwoNewLines){

    string expectedValue = "";
    string actualValue = CollapseLines::collapseNewLines("\n\n");

    EXPECT_EQ(expectedValue, actualValue);
}

TEST(CollapseLinesTest, Should_ReturnTheSameString_When_InputIsTwoCharactersFollowedByNewLine){
   
    string expectedValue = "aa\n";
    string actualValue = CollapseLines::collapseNewLines("aa\n");

    EXPECT_EQ(expectedValue, actualValue);
}

TEST(CollapseLinesTest, Should_DeleteTheLastNewLine_When_InputIsTwoCharactersFollowedByTwoNewLines){

    string expectedValue = "aa\n";
    string actualValue = CollapseLines::collapseNewLines("aa\n\n");

    EXPECT_EQ(expectedValue, actualValue);
}

TEST(CollapseLinesTest, Should_DeleteAllNewLines_When_InputIsSingleCharacterFollowedByTwoNewLines){

    string expectedValue = "a";
    string actualValue = CollapseLines::collapseNewLines("\n\na");

    EXPECT_EQ(expectedValue, actualValue);
}
