#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter The Value"<<endl;
    cin>>n;

    int i = 1;
    while(i<=n)
    {
        int space = n - i;
        while(space)
        {
        cout<<" ";
        space-=1;
        }

        int j = 1;
        while(j<=i)
        {
            cout<<"*";
            j+=1;
        
        }
        cout<<endl;
        i+=1;
    }
}