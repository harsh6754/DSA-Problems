#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    cout<<n<<endl;;
    cout<<&n<<endl;
    int *ptr = &n;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;


    double d ;
    cin>>d;
    double *ptr2 = &d;
    cout<<*ptr2<<endl;
    cout<<ptr<<endl;

    cout<<sizeof(n)<<endl;
    cout<<sizeof(d)<<endl;
    cout<<sizeof(ptr)<<endl;
    cout<<sizeof(ptr2)<<endl;

cout<<endl;
    int i;
    cin>>i;

    int *q = &i;
    cout<<q<<endl;
    cout<<*q<<endl;

    int *p = 0;
    p = &i;

    cout<<p<<endl;
    cout<<*p<<endl;

    cout<<endl;

    int pointer;
    cin>>pointer;
    cout<<"a before"<<pointer<<endl;
    int a = pointer;
    a++;
    cout<<"a after"<<pointer<<endl;

    int *pt = &pointer;
    cout<<"before"<<pointer<<endl;
    (*pt)++;
    cout<<"After"<<pointer<<endl;

    return 0;


}