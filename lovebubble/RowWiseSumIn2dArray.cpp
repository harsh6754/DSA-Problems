#include <bits/stdc++.h>
using namespace  std;

bool isPresent(int arr[][4],int target,int i,int j){
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
};

void printSum(int arr[][4],int i,int j)
{
    cout<<"printing the sum -> "<<endl;

    for(int i=0;i<3;i++)
    
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            sum += arr[i][j];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}

void printColSum(int arr[][4],int i,int j)
{
    cout<<"Printing Sum ->"<<endl;
    for(int j =0 ; j<4;j++)
    {
        int sum = 0;
        for(int i = 0;i<3;i++)
        {
            sum+=arr[i][j];
        }
        cout<<sum<<" ";
    } 
    cout<<endl;
};

int largestRowSum(int arr[][4],int i,int j)
{
    int maxi = INT_MIN;
    int rowIndex = -1;
    for(int i=0;i<3;i++)
    {
        int sum = 0;
        for(int j=0;j<4;j++)
        {
            sum += arr[i][j];
        }
        if(sum > maxi )
        {
            maxi = sum ;
            rowIndex = i;
        }
    }
    cout<<"The largest row sum is "<<maxi<<endl;
    return rowIndex;
}


int main()
{
    int arr[3][4];
    cout<<"Enter the Element here "<<endl;
    for(int i= 0;i<3;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Element U want to "<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j= 0 ; j<4;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the Element U wnt to Search"<<endl;
    int target;
    cin>>target;

    if(isPresent(arr,target,3,4)){
        cout<<"Element are Found "<<endl;
    }
    else {
        cout<<"Element not found"<<endl;
    }

    printSum(arr,3,4);
    printColSum(arr,3,4);

    cout<<"Max row at index "<<largestRowSum(arr,3,4)<<endl;
    return 0;
}
