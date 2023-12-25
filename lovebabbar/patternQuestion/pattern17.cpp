#include<iostream>
using namespace std;
int main()
{
    int n ;
    cout<<"Enter The value"<<endl;
    cin>>n;

    int i = 1;
    while(i<=n)
    {
        int j = 1;
        while(j<=n)
        {
            char ch ='A'- j + 1;
            cout<<ch<<" ";
            j+=1;
        }
        cout<<endl;
        i+=1;
    }
}