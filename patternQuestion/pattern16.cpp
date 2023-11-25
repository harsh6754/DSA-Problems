#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter The Value "<<endl;
    cin>>n;

    int i = 1;
    while(i<=n)
    {
        int j = 1;
        while(j<=n)
        {
            char ch = 'A' + j -1;
            cout<<ch<<" ";
            ch+=1;
            j+=1;
        }
        cout<<endl;
        i+=1;
    }

}