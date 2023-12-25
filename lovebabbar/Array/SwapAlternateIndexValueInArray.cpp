#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

void SwapAlternative(int arr[],int size)
{
    for(int i = 0;i<size;i+=2)
    {
        if(i+1<size)
        {
            swap(arr[i],arr[i+1]);
            
        }
    }
}

int main()
{
    int size;
    cout<<"Enter The Size Of Array Here"<<endl;
    cin>>size;

    int arr[100];
    for(int i = 0;i<size;i++)
    {
        cin>>arr[i];
    }

    SwapAlternative(arr,size);
    printArray(arr,size);


    return 0;
}