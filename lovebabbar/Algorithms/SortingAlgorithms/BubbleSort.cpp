#include<bits/stdc++.h>
using namespace std;

void BubbleSort(vector<int> &arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n-i; j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]); // Added a semicolon here
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the Size of array" << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter Array Element" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    BubbleSort(arr, n); // Removed the unnecessary cout here

    cout << "Sorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
