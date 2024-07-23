#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> frequencySort(vector<int> &nums){
        unordered_map<int, int> freq;
        for (auto &num : nums){
            freq[num]++;
        }
        map<int, vector<int>> freqGrp;
        for (auto &it : freq){
            freqGrp[it.second].push_back(it.first);
        }
        vector<int> ans;
        for (auto &it : freqGrp){
            if (it.second.size() > 1){
                sort(it.second.rbegin(), it.second.rend());
            }
            for (auto &num : it.second){
                for (int i = 0; i < it.first; i++){
                    ans.push_back(num);
                }
            }
        }
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
    vector<int> result = solution.frequencySort(nums);
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}