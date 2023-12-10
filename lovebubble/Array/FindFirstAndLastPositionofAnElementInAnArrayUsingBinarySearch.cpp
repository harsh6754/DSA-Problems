#include <bits/stdc++.h>
using namespace std;

pair<int, int> getFirstAndLastPosition(vector<int> arr, int n, int x) {
    int start = 0;
    int end = n - 1;
    int first = -1;
    int last = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            first = mid;
            end = mid - 1;
        } else if (x > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    start = 0;
    end = n - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == x) {
            last = mid;
            start = mid + 1;
        } else if (x > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return make_pair(first, last);
}

int main() {
    int n;
    cout << "Enter the Array Size You Want" << endl;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the Array Element" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the Array Element You Want To Find First And Last Position In Array" << endl;
    cin >> x;

    pair<int, int> result = getFirstAndLastPosition(arr, n, x);

    if (result.first != -1) {
        cout << "First occurrence: " << result.first << endl;
        cout << "Last occurrence: " << result.second << endl;  // Corrected here
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
