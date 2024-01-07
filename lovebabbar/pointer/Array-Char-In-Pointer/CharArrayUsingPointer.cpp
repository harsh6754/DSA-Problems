#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<arr<<endl;

    char ch[n];
    cin>>ch;

    cout<<ch<<endl;

    cout<<endl;

    char *c = &ch[0];
    cout<<c<<endl;
    cout<<*c<<endl;


    cout<<endl;


    char temp = 'Z';
    char *t = &temp;
    cout<<t<<endl;
    


    return 0;
}