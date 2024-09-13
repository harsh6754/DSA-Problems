#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int insertPos = 0; 
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[insertPos++] = nums[i];
            }
        }
        for (int i = insertPos; i < n; ++i) {
            nums[i] = 0;
        }
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    Solution solution;
    solution.moveZeroes(nums);
    for(int i = 0;i<n;i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}