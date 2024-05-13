#include<iostream>
#include<algorithm>
using namespace std;


void sortInWave(int arr[], int n)
{
    sort(arr, arr+n);

    for (int i=0; i<n-1; i += 2)
        swap(arr[i], arr[i+1]);
}
int main()
{
    int arr[] = {20, 10, 8, 6, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortInWave(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
}