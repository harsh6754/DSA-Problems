#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,fact=1;
    double result;
    cin>>n;

    for(i = 1;i<=n;i++)
    {
        fact*=i;
    }
    result=1.0/fact;
    cout<<result;


}