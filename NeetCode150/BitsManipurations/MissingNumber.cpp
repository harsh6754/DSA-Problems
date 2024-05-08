#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = n * (n + 1) / 2;
        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];
        }
        return sum;
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
    int result = solution.missingNumber(nums);
    cout << result;

    return 0;
}