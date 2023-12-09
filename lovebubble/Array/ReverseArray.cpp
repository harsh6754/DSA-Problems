#include <bits/stdc++.h>
using namespace std;

void reverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        // Swap elements at start and end
        swap(arr[start], arr[end]);

        // Move to the next pair of elements
        start++;
        end--;
    }
}

int main()
{
    int size;
    cout << "Enter the Array Size" << endl;
    cin >> size;

    int arr[100];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Reverse the array
    reverseArray(arr, size);

    // Print the reversed array
    cout << "Reversed Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
