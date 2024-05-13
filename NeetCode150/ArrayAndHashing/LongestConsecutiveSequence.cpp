#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());

        int cnt = 1;  
        int maxi = 0; 
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1) {
                    cnt++;
                } else {
                    maxi = max(maxi, cnt);
                    cnt = 1;
                }
            }
        }
        return max(maxi, cnt);
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

    Solution solution;
    int result = solution.longestConsecutive(nums);
    cout<<result;

    return 0;
}