#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> diff1, diff2;
        
        for (int num : set1) {
            if (set2.find(num) == set2.end()) {
                diff1.push_back(num);
            }
        }
        
        for (int num : set2) {
            if (set1.find(num) == set1.end()) {
                diff2.push_back(num);
            }
        }
        
        return {diff1, diff2};
    }
};

int main() {
    int ele1, ele2;
    cin >> ele1 >> ele2;

    vector<int> nums1(ele1);
    vector<int> nums2(ele2);

    for (int i = 0; i < ele1; i++) {
        cin >> nums1[i];
    }

    for (int i = 0; i < ele2; i++) {
        cin >> nums2[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.findDifference(nums1, nums2);
    
    for (auto &list : result) {
        for (int num : list) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
