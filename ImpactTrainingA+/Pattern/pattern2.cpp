#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;

    int columns = 1;
    while(columns<=n)
    {
        int rows =  1;
        while(rows<=columns)
        {
            cout<<"*"<<" ";
            rows+=1;
        }
        cout<<endl;
        columns+=1;
    }
    return 0;
}