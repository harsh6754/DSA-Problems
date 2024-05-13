#include<bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans = nums[0] + nums[1] + nums[2];

    sort(begin(nums), end(nums));

    for (int i = 0; i + 2 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        const int sum = nums[i] + nums[l] + nums[r];
        if (sum == target)
          return sum;
        if (abs(sum - target) < abs(ans - target))
          ans = sum;
        if (sum < target)
          ++l;
        else
          --r;
      }
    }

    return ans;
  }
};
int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }

    int target;
    cin>>target;

    Solution solution;
    int result = solution.threeSumClosest(nums,target);
    cout<<result;

    return 0;
}