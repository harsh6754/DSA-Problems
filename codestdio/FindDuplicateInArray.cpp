#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr,int n)
{
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans = ans^arr[i];
    }
    for(int i = 1;i<n;i++)
    {
        ans = ans^i;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Duplicate Value"<<findDuplicate(arr,n)<<endl;

    return 0;
}