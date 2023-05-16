#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace Person {
    using namespace std;
    class InvalidAgeException : public runtime_error {
    public:
        InvalidAgeException(const string& errorMessage) : runtime_error(errorMessage) {}
    };

    class InvalidGenderException : public runtime_error {
    public:
        InvalidGenderException(const string& errorMessage) : runtime_error(errorMessage) {}
    };

    class Person {
    private:
        string name;
        int age;
        string gender; // Male, Female

    public:
        Person(const string& name, int age, const string& gender) {
            if (age < 0 || age > 130) {
                throw InvalidAgeException("No es posible tener " + to_string(age) + " años.");
            }
            if (gender != "Female" && gender != "Male") {
                throw InvalidGenderException("El género " + gender + " no se contempla en este programa.");
            }
            this->name = name;
            this->age = age;
            this->gender = gender;
        }

        Person() : Person("", -1, "") {}

        int getAge() const {
            return age;
        }

        string getGender() const {
            return gender;
        }

        double* averageAgePerGender(const vector<Person>& persons) {
            int numberOfMen = 0;
            int numberOfWomen = 0;
            int ageAccumulatorForMen = 0;
            int ageAccumulatorForWomen = 0;

            for (const Person& currentPerson : persons) {
                string currentGender = currentPerson.getGender();
                if (currentGender == "Male") {
                    numberOfMen++;
                    ageAccumulatorForMen += currentPerson.getAge();
                }
                else {
                    numberOfWomen++;
                    ageAccumulatorForWomen += currentPerson.getAge();
                }
            }

            double averageForMen = (numberOfMen == 0) ? 0 : (static_cast<double>(ageAccumulatorForMen) / numberOfMen);
            double averageForWomen = (numberOfWomen == 0) ? 0 : (static_cast<double>(ageAccumulatorForWomen) / numberOfWomen);

            double* averages = new double[2];
            averages[0] = averageForMen;
            averages[1] = averageForWomen;

            return averages;
        }
    };
}
