#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int ans = 0, div;
        for(auto val:nums1)
        {
            for(auto v:nums2)
            {
                div = v * k;
                if(val % div == 0) ans++;
            }
        }
        return ans;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>nums1(n),nums2(n);
    for(int i = 0;i<n;i++){
        cin>>nums1[i];
    };
    for(int i = 0;i<n;i++){
        cin>>nums2[i];
    };
    int k;
    cin>>k;
    Solution solution;
    int result = solution.numberOfPairs(nums1,nums2,k);
    cout<<result;


    return 0;
}