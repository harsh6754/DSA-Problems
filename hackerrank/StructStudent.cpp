#include<iostream>
using namespace std;

struct student{
    int age,marks,standard;
    string name;
};
int main()
{
    student st;
    cout<<"enter student age:"<<endl;
    cin>>st.age;
    cout<<"enter student name:"<<endl;
    cin>>st.name;
    cout<<"enter student standard:"<<endl;
    cin>>st.standard;
    cout<<"enter marks"<<endl;
    cin>>st.marks;
     return 0;


}