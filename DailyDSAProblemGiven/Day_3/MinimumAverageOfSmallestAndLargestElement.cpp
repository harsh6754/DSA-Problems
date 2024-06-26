#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        vector<double> ans;
        sort(nums.begin(), nums.end());
        while(nums.size()) {
            double f =(double) nums.front();
            nums.erase(nums.begin());

            double l = (double)nums.back();
            nums.pop_back();
            double avg = (l + f) / 2.0;
            ans.push_back(avg);
        }
        return *min_element(ans.begin(), ans.end());
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
    double result = solution.minimumAverage(nums);
    cout<<result;


    return 0;
}