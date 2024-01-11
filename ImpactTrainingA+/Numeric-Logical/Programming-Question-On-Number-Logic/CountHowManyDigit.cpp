#include<bits/stdc++.h>
using namespace std;

int countDigit(int n){
    int count = 0;
    while(n!=0)
    {
        n = n/10;
        count+=1;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;


    cout<<countDigit(n)<<endl;
    return 0;
}