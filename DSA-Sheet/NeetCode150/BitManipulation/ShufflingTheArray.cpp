#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        // Loop to merge the two halves alternatively
        for (int i = 0; i < n; ++i) {
            result.push_back(nums[i]);       // Take from first half
            result.push_back(nums[i + n]);   // Take from second half
        }
        return result;
    }
};

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (auto& x : nums) cin >> x;

    int n;
    cin >> n;

    Solution solution;
    vector<int> result = solution.shuffle(nums, n);

    // Print the result
    for (auto& i : result) cout << i << " ";
    cout << endl;

    return 0;
}

