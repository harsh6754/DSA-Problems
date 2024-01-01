#include<bits/stdc++.h>
using namespace std;

int DistinctElement(int arr[],int n){
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==arr[i+1])
        {
            count+=1;
        }
    }
    return count;
}

int main()
{
  int n;
  cin>>n;


   int arr[100];
  for(int i = 0;i<n;i++)
  {
    cin>>arr[i];
  }


  cout<<DistinctElement(arr,n);
  return 0;
}