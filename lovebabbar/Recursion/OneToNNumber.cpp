#include<bits/stdc++.h>
using namespace std;

void find (int n)
{
    if(n==0)
    return;
    find(n-1);
    cout<<n<<" ";
}

int main()
{
    int n = 5 ;
    //cout<<"Enter the number";
    //cin>>n;

    find(n);

    return 0;


}