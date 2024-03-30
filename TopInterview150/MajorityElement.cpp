#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        n = n / 2;
        for (auto x : m)
        {
            if (x.second > n)
            {
                return x.first;
            }
        }
        return 0;
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
    int result = solution.majorityElement(nums);
    cout << result;

    return 0;
}