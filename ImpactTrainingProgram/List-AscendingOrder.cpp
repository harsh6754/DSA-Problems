#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int size;

    // Input size of the array
    cin >> size;

    // Input array elements
    int arr[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Sorting the array using bubble sort
    bubbleSort(arr, size);

    // Output the sorted array
    cout << "The Sorted array is:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
