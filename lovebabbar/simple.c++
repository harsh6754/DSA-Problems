#include<iostream>
using namespace std;
int main()
{
    int Total;
    int Present_Student;
    int Absent_Student;
    cout<<"Enter The Value"<<endl;
    cin>>Present_Student;
    cin>>Absent_Student;

Total = Present_Student - Absent_Student;

cout<<"Total Student Present in Class -> "<<Total<<endl;
return 0;

}