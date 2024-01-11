#include<bits/stdc++.h>
using namespace std;

int SumOfNaturalNumber(int n)
{
    int sum = 0;
    for(int i = 1;i<n;i++)
    {
        sum+=i;
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;

    cout<<SumOfNaturalNumber(n)<<endl;


    return 0;
}