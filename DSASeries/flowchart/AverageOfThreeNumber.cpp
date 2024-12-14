#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double averageOfNumber(vector<int>& arr) {
        int size = arr.size();
        double sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return (sum / size);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    double result = solution.averageOfNumber(arr);
    cout << fixed << setprecision(2) << result; // Ensures the output is formatted with 6 decimal places

    return 0;
}
