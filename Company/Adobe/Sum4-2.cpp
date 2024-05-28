#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4)
    {

        int count = 0;
        unordered_map<int, int> mp;
        for (auto &it1 : nums1)
            for (auto &it2 : nums2)
                mp[it1 + it2]++;

        for (auto &it3 : nums3)
            for (auto &it4 : nums4)
                if (mp.count(0 - it3 - it4))
                    count += mp[0 - it3 - it4];

        return count;
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> nums1(n);
    vector<int> nums2(n);
    vector<int> nums3(n);
    vector<int> nums4(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums2[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums3[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> nums4[i];
    }

    Solution solution;
    int result = solution.fourSumCount(nums1, nums2, nums3, nums4);
    cout << result;

    return 0;
}