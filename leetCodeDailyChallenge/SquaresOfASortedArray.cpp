#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            nums[i] = nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};

int main()
{
    int n;
    cout<<"Enter The Size of Array"<<endl;
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter The Element"<<endl;
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }

    Solution solution;
    vector<int>result = solution.sortedSquares(nums);
    for(int i = 0;i<nums.size();i++)
    {
        cout<<nums[i]<<" ";
    }

    return 0;
}