#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};

int main(){
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0; i<n;i++)
    {
       cin>>nums[i];
    }

    Solution solution;
    int result = solution.removeDuplicates(nums);
    cout<<result;



    return 0;
}