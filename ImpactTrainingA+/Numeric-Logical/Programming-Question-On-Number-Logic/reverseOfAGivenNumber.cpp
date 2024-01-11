#include<bits/stdc++.h>
using namespace std;

int ReverseOfAGivenNumber(int n)
{
    int num = 0;
    while(n!=0)
    {
        int ans = n%10;
        n/=10;
        num = num*10+ans;
    }
    return num;
}
int main()
{
    int n;
    cin>>n;

    cout<<ReverseOfAGivenNumber(n)<<endl;
    return 0;
}