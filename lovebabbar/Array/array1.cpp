#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int n = 15;
    int arr[n]={2,7,8,9,10,1,0};
    int arrsize = sizeof(arr)/sizeof(int);
    cout<<arrsize<<endl;

    printArray(arr,15);
    
}