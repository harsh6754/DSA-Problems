#include<iostream>
using namespace std;
int main()
{
    int i;
    i=5;
    int *p=&i;
    int **p2=&p;

    cout<<"P Ka Address:"<<p<<endl;
    cout<<"P ki Value :"<<*p<<endl;
    cout<<"p ki value ka address:"<<&p<<endl;

    cout<<endl<<endl;


    cout<<p2<<endl;
    cout<<*p2<<endl;
    cout<<&p2<<endl;

    cout<<p<<endl;

    //i=i+1;
    //i=i*2;
    cout<<i<<endl;
    cout<<*p<<endl;
    cout<<**p2<<endl;

    cout<<&i<<endl;
    cout<<p<<endl;
    cout<<*p2<<endl;

    cout<<&p<<endl;
    cout<<p2<<endl;


    return 0;
}