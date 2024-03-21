#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int target)
    {
        int count = 0;
        sort(nums.begin(), nums.end());

        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] < target)
            {
                count += (right - left);
                left++;
            }
            else
            {
                right--;
            }
        }
        return count;
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

    int target;
    cin >> target;

    Solution solution;
    int result = solution.countPairs(nums, target);
    cout << result;

    return 0;
}
