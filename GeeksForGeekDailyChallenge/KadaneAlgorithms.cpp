#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySum(vector<int>& arr) {
        int size = arr.size();
        long long sum = 0;  // You can use long long if you expect large values
        int ans = INT_MIN;  // Initialize to a very small value

        for (int i = 0; i < size; i++) {
            sum += arr[i];

            // Update the maximum sum
            ans = max(ans, (int)sum);

            // If sum becomes negative, reset it to 0
            if (sum < 0) {
                sum = 0;
            }
        }

        return ans;  // Return the maximum subarray sum
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution solution;
    int result = solution.maxSubarraySum(arr);

    // Output the result
    cout << result << endl;

    return 0;
}
