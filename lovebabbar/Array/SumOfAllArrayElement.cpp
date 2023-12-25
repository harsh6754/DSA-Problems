#include<bits/stdc++.h>
using namespace std;


int getSumOfAllArray(int arr[],int n)
{
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int main()
{
    int size;
    cout<<"Enter the Size of Array Here --->"<<endl;
    cin>>size;


    int arr[100];
    for(int i = 0;i<size;i++)
    {
         cin>>arr[i];
    }

    cout<<"Sum Of All Array Element ---->"<<getSumOfAllArray(arr,size)<<endl;


    return 0;
}