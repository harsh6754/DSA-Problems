#innclude<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int majorityElement(vector<int>&nums){
        int size = nums.size();
        unordered_map<int,int>mp;
        for(int i = 0;i<size;i++){
            mp[nums[i]]++;
        }
       for(auto& i : mp) {
            if(i.second > size / 2) {
                return i.first;
            }
        }
        return -1;
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
    int result = solution.majorityElement(nums);
    cout<<result;

    return 0;
}