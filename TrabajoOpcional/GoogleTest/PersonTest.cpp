#include "pch.h"
#include <gtest/gtest.h>
#include <vector>
#include <stdexcept>

#include "..\ClasesAProbar\Person\Person.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\Person.cpp>
#include "..\ClasesAProbar\Person\InvalidAgeException.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidAgeException.cpp>
//#include <C:\Users\Dani\OneDrive\Documentos\Uni\3o\Mantenimiento\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidAgeException.cpp>
#include "..\ClasesAProbar\Person\InvalidGenderException.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidGenderException.cpp>
//#include <C:\Users\Dani\OneDrive\Documentos\Uni\3o\Mantenimiento\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidGenderException.cpp>



using namespace std;
using namespace testing;

class PersonTest : public ::testing::Test {
};

TEST(PersonTest, Mean_age_for_no_people_is_zero) {
    Person person = Person();
    vector<Person> personList;
    double* obtainedValue;
    double expectedValue[2] = { 0, 0 };

    obtainedValue = person.averageAgePerGender(personList);

    for (int i = 0; i < sizeof(expectedValue) / sizeof(expectedValue[0]); i++)
        ASSERT_EQ(expectedValue[i], obtainedValue[i]);
}

TEST(PersonTest, Mean_age_for_one_person_is_their_age) {
    Person person = Person();
    int age = 20;
    vector<Person> personList;
    personList.push_back(Person("María", age, "Female"));
    double* obtainedValue;
    double expectedValue[2] = { 0.0, (double) age };

    obtainedValue = person.averageAgePerGender(personList);

    for (int i = 0; i < sizeof(expectedValue) / sizeof(expectedValue[0]); i++)
        ASSERT_EQ(expectedValue[i], obtainedValue[i]);
}

TEST(PersonTest, Mean_age_for_several_people_returns_their_mean_age) {
    Person person = Person();
    vector<Person> personList;
    personList.push_back(Person("María", 20, "Female"));
    personList.push_back(Person("John", 25, "Male"));
    personList.push_back(Person("Jane", 30, "Female"));
    personList.push_back(Person("Jim", 35, "Male"));
    personList.push_back(Person("Joan", 40, "Female"));
    double* obtainedValue;
    double expectedValue[2] = { 30, 30 };

    obtainedValue = person.averageAgePerGender(personList);
    
    for (int i = 0; i < sizeof(expectedValue) / sizeof(expectedValue[0]); i++)
        ASSERT_EQ(expectedValue[i], obtainedValue[i]);
}

TEST(PersonTest, Creating_a_Person_with_negative_age_throws_InvalidAgeException) {
    ASSERT_THROW(Person("John Doe", -1, "Male"), InvalidAgeException);
}

TEST(PersonTest, Creating_a_Person_with_too_high_age_throws_InvalidAgeException) {
    ASSERT_THROW(Person("John Doe", 500, "Male"), InvalidAgeException);
}

TEST(PersonTest, Creating_a_Person_with_an_invalid_gender_throws_InvalidGenderException) {
    ASSERT_THROW(Person("John Doe", 30, "Other"), InvalidGenderException);
}
