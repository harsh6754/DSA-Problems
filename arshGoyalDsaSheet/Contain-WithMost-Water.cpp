#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r)
        {
            int max_pos_height = min(height[l], height[r]);
            ans = max(ans, (r - l) * max_pos_height);
            while (l < r && height[l] <= max_pos_height) l++;
            while (l < r && height[r] <= max_pos_height) r--;
        }
        return ans;
    }
};

int main()
{
    int n;
    cin>>n;

    vector<int>height(n);
    for(int i = 0;i<n;i++)
    {
        cin>>height[i];
    }

    Solution solution;
    int Area = solution.maxArea(height);
    cout<<Area<<endl;

    return 0;
}