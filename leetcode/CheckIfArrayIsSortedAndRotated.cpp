#include<bits/stdc++.h>
using namespace std;

bool isIncRotated(int arr[], int n, int minIndex, int maxIndex);
bool isDecRotated(int arr[], int n, int minIndex, int maxIndex);
bool isIncreasing(int arr[], int l, int r);
bool isDecreasing(int arr[], int l, int r);

void checkIfSortRotated(int arr[], int n)
{
    int minEle = INT_MAX;
    int maxEle = INT_MIN;

    int minIndex = 0;
    int maxIndex = 0;

    // Find the index of minimum & maximum element
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }

    bool res = false;

    if (maxIndex == minIndex - 1)
    {
        res = isIncRotated(arr, n, minIndex, maxIndex);
    }

    if (minIndex == maxIndex - 1)
    {
        res = isDecRotated(arr, n, minIndex, maxIndex);
    }

    if (res)
        cout << "YES";
    else
        cout << "NO";
}

bool isIncRotated(int arr[], int n, int minIndex,
                  int maxIndex)
{
    if (arr[0] < arr[n - 1])
    {
        return false;
    }

    return isIncreasing(arr, 0, maxIndex) &&
           isIncreasing(arr, minIndex, n - 1);
}

bool isDecRotated(int arr[], int n, int minIndex,
                  int maxIndex)
{
    if (arr[0] > arr[n - 1])
    {
        return false;
    }

    return isDecreasing(arr, 0, minIndex) &&
           isDecreasing(arr, maxIndex, n - 1);
}

bool isIncreasing(int arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i - 1] > arr[i])
            return false;
    }

    return true;
}

bool isDecreasing(int arr[], int l, int r)
{
    for (int i = l + 1; i <= r; i++)
    {
        if (arr[i - 1] < arr[i])
            return false;
    }

    return true;
}

// Driver code
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Function Call
    checkIfSortRotated(arr, n);
    return 0;
}
