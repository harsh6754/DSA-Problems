#include<iostream>
using namespace std;
int main()
{
    char name[20];
    cout<<"enter you name baby"<<endl;
    cin>>name;
    name[20] = '\0';

    cout<<"your name is ";
    cout<<name<<endl;
}