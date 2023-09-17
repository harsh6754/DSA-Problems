#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int findDuplicate(vector<int> &arr)
{
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int index = abs(arr[i]) - 1;
        if (arr[index] > 0)
        {
            arr[index] = -arr[index]; // Mark as visited by making it negative
        }
        else
        {
            return abs(arr[i]);
        }
    }

    return -1; // If no duplicate found, you can return -1 or any other appropriate value.
}

int main()
{
    vector<int> arr = {1, 3, 2, 2, 4, 5, 6, 7, 8, 9};
    cout << "The duplicate element is " << findDuplicate(arr) << endl;
    return 0;
}
