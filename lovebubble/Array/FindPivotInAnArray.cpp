#include <bits/stdc++.h>
using namespace std;

int getPivot(int arr[],int n){
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start<end){
        if(arr[mid]>=arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}

int main()
{
    int n;
    cout << "Enter the size of array:" << endl;
    cin >> n;

    int arr[100];

    cout << "Enter the array Element" << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
    }


    int pivot = getPivot(arr,n);
    cout<<"Pivot is "<<pivot<<endl;
    return 0;
}
