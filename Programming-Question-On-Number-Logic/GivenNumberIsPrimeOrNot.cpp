#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    int count = 0;
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            count+=1;
        }
    }
    return count==0;
}

int main()
{
    int n;
    cin>>n;

    if(isPrime)
    {
        cout<<n<<" "<<"Its A Prime Number"<<endl;
    }
    else{
        cout<<n<<" "<<"Its Not A Prime Number"<<endl;
    }

    return 0;
    }