#include<bits/stdc++.h>
using namespace std;
class Student{
    public: 
    string name;
    Student(){
        cout<<"Non-Parametrized"<<endl;
    }

    Student (string name){
        this->name = name;
        cout<<"Parameterized "<<endl;
    }
};

int main(){
    Student s1("Harsh");
    return 0;
}