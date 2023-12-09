#include<bits/stdc++.h>
using namespace std;

int getSecondMaxValue(int arr[], int n)
{
    if (n < 2)
    {
        cout << "Array size should be at least 2." << endl;
        return -1; // Return an invalid value
    }

    int maxVal = INT_MIN;
    int secondMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            secondMax = maxVal;
            maxVal = arr[i];
        }
        else if (arr[i] > secondMax && arr[i] < maxVal)
        {
            secondMax = arr[i];
        }
    }

    return secondMax;
}

int getSecondMinValue(int arr[], int n)
{
    if (n < 2)
    {
        cout << "Array size should be at least 2." << endl;
        return -1; // Return an invalid value
    }

    int minVal = INT_MAX;
    int secondMin = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minVal)
        {
            secondMin = minVal;
            minVal = arr[i];
        }
        else if (arr[i] < secondMin && arr[i] > minVal)
        {
            secondMin = arr[i];
        }
    }

    return secondMin;
}

int main()
{
    int size;
    cout << "Enter the Size of Array: ";
    cin >> size;

    int arr[100];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Second Largest Value in Array ---> " << getSecondMaxValue(arr, size) << endl;
    cout << "Second Minimum Value in Array ---> " << getSecondMinValue(arr, size) << endl;

    return 0;
}
