#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the value"<<endl;
    cin>>n;

    int i = 1;
    while(i<=n)
    {
        int j = 1;
        int value  = i;
        while(j<=n)
        {
            cout<<value<<" ";
            value+=1;
            j+=1;
        }
        cout<<endl;
        i+=1;
    }

}