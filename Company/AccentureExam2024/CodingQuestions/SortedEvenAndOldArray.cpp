#include <iostream>
#include <vector>
using namespace std;

// Function to take input for the array
void inputArray(vector<int>& arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << "Enter element at index " << i << ": ";
        int value;
        cin >> value;
        arr.push_back(value);
    }
}

// Function to separate even and odd index elements
void separateArrays(const vector<int>& arr, vector<int>& even, vector<int>& odd) {
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }
}

// Function to sort an array using Bubble Sort
void sortArray(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

// Function to print an array
void printArray(const vector<int>& arr, const string& arrayName) {
    cout << arrayName << ": ";
    for (int element : arr) {
        cout << element << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int length;
    cout << "Enter the length of the array: ";
    cin >> length;

    vector<int> arr, even, odd;

    inputArray(arr, length);               // Step 1: Input array
    separateArrays(arr, even, odd);        // Step 2: Separate even and odd index elements
    sortArray(even);                       // Step 3: Sort even array
    sortArray(odd);                        // Step 4: Sort odd array

    printArray(even, "Sorted even array"); // Step 5: Print sorted even array
    printArray(odd, "Sorted odd array");   // Step 6: Print sorted odd array

    // Step 7: Compute and print result
    if (even.size() > 1 && odd.size() > 1) {
        int result = even[even.size() - 2] + odd[odd.size() - 2];
        cout << "Result (sum of second last elements): " << result << endl;
    } else {
        cout << "Not enough elements to compute result!" << endl;
    }

    return 0;
}
