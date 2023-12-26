#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    int m;
    cin>>m;

    int arr[n][m];
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[j][i];
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}