#include<iostream>
using namespace std;

void print(int arr[],int start,int n=10)
{
    for(int i = start;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
};

int main()
{
   int  arr[5]={1,2,3,4,5};
    int size=5;
    print(arr,size,0);

    return 0;
}