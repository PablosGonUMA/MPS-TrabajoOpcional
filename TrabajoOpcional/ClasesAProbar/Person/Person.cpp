#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Person.h"

#include "C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidAgeException.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidAgeException.cpp>
#include "C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidGenderException.h"
#include <C:\Users\pablo\Desktop\MPS-TrabajoOpcional\TrabajoOpcional\ClasesAProbar\Person\InvalidGenderException.cpp>

Person::Person(const string& name, int age, const string& gender) {
    if (age < 0 || age > 130)
        throw InvalidAgeException("No es posible tener " + to_string(age) + " años.");

    if (gender != "Female" && gender != "Male")
        throw InvalidGenderException("El género " + gender + " no se contempla en este programa.");

    this->name = name;
    this->age = age;
    this->gender = gender;
}

Person::Person() : Person("Noname", 0, "Male") {}

int Person::getAge() const {
    return age;
}

string Person::getGender() const {
    return gender;
}

double* Person::averageAgePerGender(const vector<Person>& persons) {
    int numberOfMen = 0;
    int numberOfWomen = 0;
    int ageAccumulatorForMen = 0;
    int ageAccumulatorForWomen = 0;

    for (const Person& currentPerson : persons) {
        string currentGender = currentPerson.getGender();
        if (currentGender == "Male") {
            numberOfMen++;
            ageAccumulatorForMen += currentPerson.getAge();
        } else {
            numberOfWomen++;
            ageAccumulatorForWomen += currentPerson.getAge();
        }
    }

    double averageForMen = (numberOfMen == 0) ? 0 : ((double) (ageAccumulatorForMen) / numberOfMen);
    double averageForWomen = (numberOfWomen == 0) ? 0 : ((double) (ageAccumulatorForWomen) / numberOfWomen);

    double* averages = new double[2];
    averages[0] = averageForMen;
    averages[1] = averageForWomen;

    return averages;
}

