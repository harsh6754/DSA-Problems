#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& arr, int k, int n, int mid){
    int cows = 1;
    int prev = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] - prev >= mid) {
            cows++;
            prev = arr[i];
        }

        if (cows == k) {
            return true;
        }
    }

    return false;
}

int AggressiveCows(vector<int>& arr, int n, int k){
    sort(arr.begin(), arr.end());

    int s = 0;
    int e = arr[n - 1] - arr[0];
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;

        if (isPossible(arr, k, n, mid)) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the Number Of Store " << endl;
    cin >> n;

    // Aggressive Cows
    int k;
    cout << "Enter the Number Of Cows" << endl;
    cin >> k;

    vector<int> arr(n);
    cout << "Enter the Store" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << AggressiveCows(arr, n, k) << endl;

    return 0;
}
