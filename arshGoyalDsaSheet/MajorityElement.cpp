#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        for(auto x:nums)
        {
            m[x]++;
        }
        int n=nums.size();
        for(auto x:m)
        {
            if(x.second>n/2)
            {
                return x.first;
            }
        }
        return -1;;
    }
};
int main()
{
    int n;
    cin>>n;

    vector<int>nums(n);
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i];
    }

    Solution solution;
    int result = solution.majorityElement(nums);
    cout<<result;


    return 0;

}