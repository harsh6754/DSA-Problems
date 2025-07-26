#include<bits/stdc++.h>
using namespace std;

class Solution {
private:

    vector<int> nums;

public:
    
    Solution(vector<int>& nums) {
        // Do not allocate extra space for the nums array
        this->nums.swap(nums);
    }
    
    int pick(int target) {
        vector<int> indices;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                indices.push_back(i);
            }
        }
        int l = indices.size();
        int randomIndex = indices[rand() % l];
        return randomIndex;
    }
};

int main(){
    int n, target;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> target;

    Solution solution(nums);
    int result = solution.pick(target);
    cout << result << endl;

    return 0;
}

