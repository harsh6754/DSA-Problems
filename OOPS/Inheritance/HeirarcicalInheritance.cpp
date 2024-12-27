#include<bits/stdc++.h>
using namespace std;

class Person {
    public:
    string name;
    int age; // Missing semicolon added
};

class Student : public Person {
    public:
    long long rollno;
};

class Teacher : public Person {
    public:
    string subj;
};

class TA : public Student, public Teacher {
    public:
    void setDetails(const string& name, int age, const string& subj, long long rollno) {
        // Disambiguating the `name` and `age` attributes
        Student::name = name;
        Student::age = age;
        this->subj = subj;
        this->rollno = rollno;
    }

    void displayDetails() {
        cout << "Name: " << Student::name << endl; // Use Student's or Teacher's name explicitly
        cout << "Age: " << Student::age << endl;  // Use Student's or Teacher's age explicitly
        cout << "Subject: " << subj << endl;
        cout << "Roll Number: " << rollno << endl;
    }
};

int main() {
    TA t1;
    t1.setDetails("Harsh Agrawal", 21, "Chemical Engineering", 123456789);

    t1.displayDetails();

    return 0;
}
