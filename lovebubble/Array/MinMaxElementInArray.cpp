#include<bits/stdc++.h>
using namespace std;

int getMaxi(int arr[],int n)
{
    int maxi = INT_MIN;
    for(int i = 0;i<n;i++)
    {
         maxi=max(maxi,arr[i]);
    }
    return maxi;
}


int getMini(int arr[],int n)
{
    int mini = INT_MAX;
    for(int i = 0;i<n;i++)
    {
        mini = min(mini,arr[i]);
    }
    return mini;
}


int main()
{
    int size;
    cout<<"Enter size of Array"<<endl;
    cin>>size;

    int arr[100];

    for(int i = 0;i<size;i++)
    {
        cin>>arr[i];
    }


    cout<<"Maximum Value in Array --->"<<getMaxi(arr,size)<<endl;
    cout<<"Minimum Value in Array --->"<<getMini(arr,size)<<endl;
    return 0;
}