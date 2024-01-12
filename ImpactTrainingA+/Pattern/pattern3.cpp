#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value ";
    cin>>n;

    int rows = n;
    while(rows<=n)
    {
        int columns = n;
        while(columns<=rows)
        {
            cout<<"*"<<" ";
            columns-=1;

        }
        cout<<endl;
        rows-=1;
    }
    return 0;
}