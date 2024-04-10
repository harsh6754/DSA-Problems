#include <bits/stdc++.h> 

using namespace std;

int findDuplicate(vector<int> &arr, int n){  

    sort(arr.begin(), arr.end());

    int start=0;

    int end=n-1;

    while(start<=end){

        int mid=start+(end-start)/2;

        if (arr[mid]==arr[mid+1] || arr[mid]==arr[mid-1]){

            return arr[mid];

        }

        else if (arr[mid]>mid){

            start=mid+1;

        }

        else{

            end=mid-1;

        }

    }

    return 0;
}

int main()
{
    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<findDuplicate(arr,n)<<endl;

    return 0;
}