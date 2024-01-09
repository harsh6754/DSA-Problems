#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    int ans=0;
    if(y<x)
    {
        ans=(n*m*(y-1))+((n-1)*(m-1)*(x-y));
    }
    else
    {
        ans=n*m*x;
    }
    cout<<ans<<endl;
    return 0;
}
