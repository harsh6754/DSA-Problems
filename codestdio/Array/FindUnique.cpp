#include<bits/stdc++.h>
using namespace std;

void findUnique(int arr[], int size)
{
    unordered_map<int, int> freq;

    // Count the frequency of each element in the array
    for (int i = 0; i < size; i++) {
        freq[arr[i]]++;
    }

    // Print unique elements
    cout << "Unique elements in the array: ";
    for (auto it : freq) {
        if (it.second == 1) {
            cout << it.first << " ";
        }
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter the array Size Here: ";
    cin >> size;

    int arr[100];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    findUnique(arr, size);

    return 0;
}
