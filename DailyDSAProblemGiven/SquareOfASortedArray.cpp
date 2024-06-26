#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int sum = nums[i] * nums[i];
            ans.push_back(sum);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    Solution solution;
    vector<int> result = solution.sortedSquares(nums);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}