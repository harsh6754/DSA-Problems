#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the Value"<<endl;
    cin>>n;

    int i = 1;
    while(i<=n)
    {
        int j = 1;
        while(j<=(n-i+1))
        {
            cout<<"*"<<" ";
            j+=1;
        }
        cout<<endl;
        i+=1;
    }
}