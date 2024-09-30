#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> result_set;
        
        for(int num : nums2) {
            if(set1.count(num)) {
                result_set.insert(num);
            }
        }

        vector<int> result(result_set.begin(), result_set.end());
        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums1(n);
    for(int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    int m;
    cin >> m;

    vector<int> nums2(m);
    for(int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    Solution solution;
    vector<int> result = solution.intersection(nums1, nums2);

    for(auto& x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
