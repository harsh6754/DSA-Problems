#include<iostream>
using namespace std;

int power(int n )
{
    if(n==0)
    {
        return 1;
    }
    int A =power(n-1);
    int B= 2*A;

    return B;
}

int main()
{
    int n ;
    cin>>n;

    int ans = power(n);
    cout<<ans<<endl;

    return 0;
}