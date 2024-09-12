#include <iostream>
#include <vector>

using namespace std;

void pushZerosToEnd(vector<int> &arr)
{
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            arr[count++] = arr[i];
        }
    }

    while (count < arr.size())
    {
        arr[count++] = 0;
    }
}

int main()
{
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pushZerosToEnd(arr);

    cout << "Array after pushing all zeros to the end: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
