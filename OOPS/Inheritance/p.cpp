#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string name;
    int age;

    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
};

class Student : public Person {
public:
    long long rollno;

    // Constructor that initializes Person's attributes
    Student(string name, int age, long long rollno) : Person(name, age) {
        this->rollno = rollno;
    }
};

class GradStudent : public Student {
public:
    string researchArea;

    // Constructor that initializes Student's attributes and researchArea
    GradStudent(string name, int age, long long rollno, string researchArea)
        : Student(name, age, rollno) {
        this->researchArea = researchArea;
    }
};

int main() {
    // Create a GradStudent object with appropriate arguments
    GradStudent s1("Harsh Agrawal", 22, 101, "Quantum Physics");

    cout << "Name: " << s1.name << endl;
    cout << "Research Area: " << s1.researchArea << endl;
    return 0;
}
