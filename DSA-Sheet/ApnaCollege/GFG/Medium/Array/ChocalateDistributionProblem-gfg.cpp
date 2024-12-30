#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ChocolateDistribution(vector<int>& arr, int m) {
        int size = arr.size();
        if (m == 0 || size == 0) return 0;
        if (m > size) return -1;
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        for (int i = 0; i + m - 1 < size; i++) {
            int diff = arr[i + m - 1] - arr[i];
            minDiff = min(minDiff, diff);
        }
        return minDiff;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cin >> m;

    Solution solution;
    int result = solution.ChocolateDistribution(arr, m);
    if (result == -1) {
        cout << "Distribution not possible";
    } else {
        cout << result;
    }

    return 0;
}
