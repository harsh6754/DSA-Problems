#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int roll_number;
    int marks;
    double percentage;

    void inputDetails() {
        cout << "Enter name:" << endl;
        getline(cin, name);

        cout << "Enter roll number:" << endl;
        cin >> roll_number;

        cout << "Enter total marks out of 500:" << endl;
        cin >> marks;

        // Ensure marks do not exceed 500
        if (marks > 500) {
            marks = 500;
        }

        if(marks<0)
           marks = abs(marks);

        calculatePercentage();
    }

    void displayDetails() {
        cout << "Student details:" << endl;
        cout << "Name:" << name << endl;
        cout << "Roll Number:" << roll_number << endl;
        cout << "Total:" << marks << endl;
        cout << "Percentage:" << percentage  << endl;
    }

private:
    void calculatePercentage() {
        percentage = ((float)(marks) / 500) * 100;
    }
};

int main() {
    Student student1, student2;

    student1.inputDetails();

    student1.displayDetails();

    return 0;
}

