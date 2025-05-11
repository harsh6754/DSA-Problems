#include<bits/stdc++.h>
using namespace std;
class Teacher{
    private:
    double salary;

    public:
    string name;
    string dept;
    string subject;

    void changeDept(string newDept){
        dept = newDept;
    }

    void setSalary(double s){
        salary = s;
    }

    double getSalary(){
        return salary;
    }
};

int main(){
    Teacher t1;
    t1.name = "John Doe";
    t1.dept = "Mathematics";
    t1.subject = "Algebra";

    t1.setSalary(50000);
    cout << "Name: " << t1.name << endl;
    cout << "Department: " << t1.dept << endl;
    cout << "Subject: " << t1.subject << endl;
    cout << "Salary: $" << t1.getSalary() << endl;

    t1.changeDept("Physics");
    cout << "New Department: " << t1.dept << endl;
    return 0;
}