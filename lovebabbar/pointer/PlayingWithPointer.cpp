#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    cout<<n<<endl;;
    cout<<&n<<endl;
    int *ptr = &n;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
}