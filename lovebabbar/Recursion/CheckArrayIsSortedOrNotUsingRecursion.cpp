#include<bits/stdc++.h>
using namespace std;

bool sortArray(int n, int arr[]) {
    if (n == 0 || n == 1) {
        return true;
    }
    if (arr[0] < arr[1]) { // Changed the condition to check for non-increasing order
        return false;
    } else {
        bool remain = sortArray(n - 1, arr + 1);
        return remain;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    bool result = sortArray(n, arr);
    if (result) {
        cout << "Array is Sorted in Non-Increasing Order" << endl;
    } else {
        cout << "Array is not Sorted in Non-Increasing Order" << endl;
    }

    return 0;
}
