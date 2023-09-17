#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the value of n:"<<endl;
    cin>>n;

    int i=1;
    while(i<=n){
        for(i=1;i<=n;i++)
        {
            int j=1;
            while(j<=n)
            {
                for(j=1;j<=n;j++)
                cout<<" * "<<" ";                j+=1;
            }
        }
        cout<<endl;
        i+=1;
    }
}