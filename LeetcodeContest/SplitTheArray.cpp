#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            seen.insert(num);
        }
        
        return seen.size() == nums.size() / 2;
    }
};

int main() {
    Solution solution;
    
    // Input
    int n;
    cout << "Enter the length of the array (even number): ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Check if it's possible to split the array
    if (solution.isPossibleToSplit(nums)) {
        cout << "It is possible to split the array." << endl;
    } else {
        cout << "It is not possible to split the array." << endl;
    }

    return 0;
}
