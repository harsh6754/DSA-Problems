#include <bits/stdc++.h>
using namespace std;

int SearchArrayIndexInRotatedArray(vector<int>& arr, int x) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return mid;
        }

        if (arr[low] <= arr[mid]) {
            if (arr[low] <= x && x < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        else {
            if (arr[mid] < x && x <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1; 
}

int main() {
    int n;
    cout << "Enter the array size: ";
    cin >> n;

    int x;
    cout << "Enter the value you want to find index: ";
    cin >> x;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = SearchArrayIndexInRotatedArray(arr, x);

    if (result != -1) {
        cout << "Index of " << x << " in the rotated array: " << result << endl;
    } else {
        cout << "Element not found in the rotated array." << endl;
    }

    return 0;
}
