#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
    string gender; // Male, Female

    int checkAge(int age) {
        if (age < 0 || age > 150) 
            throw runtime_error("Invalid age: " + to_string(age));
        
        return age;
    }

    string checkGender(string gender) {
        if (!"Male"._Equal(gender) && !"Female"._Equal(gender))
            throw runtime_error("Invalid gender: \"" + gender + "\"");

        return gender;
    }

public:
    Person(const string& name, int age, const string& gender)
        : name(name), age(checkAge(age)), gender(checkGender(gender)) {}

    string getName() const {
        return name;
    }

    void setName(const string& newName) {
        name = newName;
    }

    int getAge() const {
        return age;
    }

    void setAge(int newAge) {
        age = checkAge(newAge);
    }

    string getGender() const {
        return gender;
    }

    void setGender(const string& newGender) {
        gender = checkGender(newGender);
    }
};
