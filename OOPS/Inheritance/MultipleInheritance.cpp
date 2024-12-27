#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
    string name;
    long long rollno;
};

class Teacher{
    public:
    string subj;
    double salary;
};

class TA : public Student, public Teacher{

};

int main(){
    TA t1;
    t1.name = "Harsh Agrawal";
    t1.subj = "Chemical Engineering";

    cout<<t1.name<<endl;
    cout<<t1.subj<<endl;

    return 0;
}