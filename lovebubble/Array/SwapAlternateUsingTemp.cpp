#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int n)
{
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void swapAlternate(int arr[],int size)
{
    for(int i = 0;i<size;i+=2)
    {
        int temp;
        if(i+1<size)
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}

int main()
{
    int size;
    cout<<"Enter the Array Size You Want here"<<endl;
    cin>>size;

    int arr[100];
    for(int i = 0;i<size;i++)
    {
         cin>>arr[i];
    }

    swapAlternate(arr,size);
    printArray(arr,size);
    return 0;
}