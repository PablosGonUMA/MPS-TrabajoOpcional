#include "../ClasesAProbar/Person.h";
#include <../ClasesAProbar/Person/Person.cpp>

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <stdexcept>

using namespace std;
using namespace testing;
using namespace Person;

class PersonTest : public ::testing::Test {
protected:
    Person person;

    void SetUp() override {
        person = Person();
    }
};

TEST_F(PersonTest, MeanAgeForZeroPersons) {
    vector<Person> personList;
    double obtainedValue[2];
    double expectedValue[2] = { 0, 0 };

    person.averageAgePerGender(personList, obtainedValue);

    ASSERT_THAT(obtainedValue, ::testing::ElementsAreArray(expectedValue));
}

TEST_F(PersonTest, MeanAgeForOnePerson) {
    int age = 20;
    vector<Person> personList;
    personList.push_back(Person("María", age, "Female"));
    double obtainedValue[2];
    double expectedValue[2] = { 0, age };

    person.averageAgePerGender(personList, obtainedValue);

    ASSERT_THAT(obtainedValue, ::testing::ElementsAreArray(expectedValue));
}

TEST_F(PersonTest, MeanAgeForFivePersons) {
    vector<Person> personList;
    personList.push_back(Person("María", 20, "Female"));
    personList.push_back(Person("John", 25, "Male"));
    personList.push_back(Person("Jane", 30, "Female"));
    personList.push_back(Person("Jim", 35, "Male"));
    personList.push_back(Person("Joan", 40, "Female"));
    double obtainedValue[2];
    double expectedValue[2] = { 30, 30 };

    person.averageAgePerGender(personList, obtainedValue);

    ASSERT_THAT(obtainedValue, ::testing::ElementsAreArray(expectedValue));
}

TEST(PersonTest, TestNegativeAge) {
    ASSERT_THROW(Person("John Doe", -1, "Male"), InvalidAgeException);
}

TEST(PersonTest, TestHighAge) {
    ASSERT_THROW(Person("John Doe", 500, "Male"), InvalidAgeException);
}

TEST(PersonTest, TestInvalidGender) {
    ASSERT_THROW(Person("John Doe", 30, "Other"), InvalidGenderException);
}

