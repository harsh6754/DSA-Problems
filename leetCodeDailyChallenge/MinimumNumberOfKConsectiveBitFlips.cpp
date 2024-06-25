#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int K) {
        int n = nums.size();
        vector<int> hint(n, 0);
        int flip = 0, result = 0;

        for (int i = 0; i < n; ++i) {
            if (i >= K) {
                flip ^= hint[i - K];
            }
            if (nums[i] == flip) {
                if (i + K > n) {
                    return -1;
                }
                flip ^= 1;
                hint[i] = 1;
                result++;
            }
        }
        return result;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    int k;
    cin>>k;

    Solution solution;
    int result = solution.minKBitFlips(nums,k);
    cout<<result;

    return 0;
}