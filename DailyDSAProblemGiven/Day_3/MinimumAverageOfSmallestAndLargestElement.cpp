#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        vector<double> averages;
        while (left < right) {
            double avg = (nums[left] + nums[right]) / 2.0;
            averages.push_back(avg);
            left++;
            right--;
        }
        
        return *min_element(averages.begin(), averages.end());
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
    double result = solution.minimumAverage(nums);
    cout << result << endl;

    return 0;
}
