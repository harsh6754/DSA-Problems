#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(a==0)
    {
        return b;
    }
    if(b==0)
    {
        return 0;
    }
    while(a!=b){
        if(a>b)
        {
            a = a-b;
        }
        else
        {
            b = b-a;
        }
        return a;
    }
}

int main()
{
    int a,b;
    cout<<"Enter the value of a and b : "<<endl;
    cin>>a>>b;

    int ans = gcd(a,b);

    cout<<"Gcd of "<<a << " & "<<b<<" is : "<< ans <<endl;
}
