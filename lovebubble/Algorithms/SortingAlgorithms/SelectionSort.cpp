#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void printArray(const vector<int>& arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the Array Size: " << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the Array Elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
 