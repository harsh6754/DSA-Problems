#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) {
            return *max_element(nums.begin(), nums.end());
        }
        
        set<int> unique_nums(nums.begin(), nums.end()); 
        if (unique_nums.size() < 3) {
     
            return *unique_nums.rbegin();
        }
        set<int>::iterator it = unique_nums.begin();
        advance(it, unique_nums.size() - 3);
        return *it;
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
    int result = solution.thirdMax(nums);
    cout << result;

    return 0;
}
