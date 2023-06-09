#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
private:
    string name;
    int age;
    string gender; // Male, Female

    int checkAge(int age);
    string checkGender(const string& gender);

public:
    Person(const string& name, int age, const string& gender);
    Person();

    string getName() const;
    void setName(const string& newName);

    int getAge() const;
    void setAge(int newAge);

    string getGender() const;
    void setGender(const string& newGender);

    double* averageAgePerGender(const vector<Person>& persons);
};

#endif
