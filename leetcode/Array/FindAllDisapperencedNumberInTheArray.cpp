#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size();
        
        // Step 1: Mark the presence of each number
        for (int i = 0; i < N; i++) {
            int idx = abs(nums[i]) - 1; // Get the index to mark
            if (nums[idx] > 0) { 
                nums[idx] = -nums[idx]; // Mark the number as found by making it negative
            }
        }
        
        // Step 2: Collect the missing numbers
        vector<int> result;
        for (int i = 0; i < N; i++) {
            if (nums[i] > 0) { 
                result.push_back(i + 1); // i + 1 is the missing number
            }
        }
        
        return result;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> result = solution.findDisappearedNumbers(nums);
    
    // Output the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
