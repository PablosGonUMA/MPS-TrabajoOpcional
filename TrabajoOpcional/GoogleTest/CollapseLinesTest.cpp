#include <../ClasesAProbar/CollapseLines/CollapseLines.cpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace std;
using namespace testing;
using namespace CollapseLines;

class CollapseLinesTest : public ::testing::Test {
protected:

};

TEST_F(CollapseLinesTest, EmptyStringThrowsException) {

    ASSERT_THROW(CollapseLines.collapseNewLines(""), exception);

}

