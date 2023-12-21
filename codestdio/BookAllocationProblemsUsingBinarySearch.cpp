#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int n, int m, int mid) {
    int students = 1;
    int pagesRead = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > mid) {
            return false;  // If a book has more pages than mid, it cannot be allocated to a student
        }

        if (pagesRead + arr[i] > mid) {
            students++;
            pagesRead = 0;
        }

        pagesRead += arr[i];
    }

    return students <= m;
}

int BookAllocation(vector<int>& arr, int n, int m) {
    int start = 0;
    int end = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isPossible(arr, n, m, mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the Array Size" << endl;
    cin >> n;

    int m;
    cout << "Enter the Number Of students" << endl;
    cin >> m;

    vector<int> arr(n);
    cout << "Enter the Array Elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Book Allocation: " << BookAllocation(arr, n, m) << endl;
    return 0;
}
