#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

//Creating 2D Array Using Dynamic Memory Allocation 
    int **arr = new int *[n];
    for(int i = 0;i<n;i++)
    {
        arr[i] = new int[n];
    }


//Taking Value 
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;

//Print Value
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;
}

