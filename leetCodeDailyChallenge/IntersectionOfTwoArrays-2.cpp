#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;
        vector<int> ans;
        for (int num : nums1) {
            countMap[num]++;
        }
        for (int num : nums2) {
            if (countMap[num] > 0) {
                ans.push_back(num);
                countMap[num]--;
            }
        }

        return ans;
    }
};

int main() {
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1);
    vector<int> nums2(n2);

    for (int i = 0; i < n1; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n2; i++) {
        cin >> nums2[i];
    }

    Solution solution;
    vector<int> result = solution.intersect(nums1, nums2);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
