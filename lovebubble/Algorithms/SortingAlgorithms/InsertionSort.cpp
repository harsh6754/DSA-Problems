#include<bits/stdc++.h>
using namespace std;

void InsertSort(vector<int>& arr, int n)
{
    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter the array size" << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array element" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    InsertSort(arr, n);

    cout << "InsertSort Sorted Array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
