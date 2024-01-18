#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int ind = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[ind] = nums1[i];
                i--;
            } else {
                nums1[ind] = nums2[j];
                j--;
            }
            ind--;
        }

        while (i >= 0) {
            nums1[ind] = nums1[i];
            i--;
            ind--;
        }

        while (j >= 0) {
            nums1[ind] = nums2[j];
            j--;
            ind--;
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums1(n);
    for (int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    int m;
    cin >> m;
    vector<int> nums2(m);
    for (int j = 0; j < m; j++) { // Fix the loop variable from 'i' to 'j'
        cin >> nums2[j];
    }

    Solution solution;
    solution.merge(nums1, n, nums2, m); // Fix the function call

    // Output the merged array
    for (int i = 0; i < n + m; i++) {
        cout << nums1[i] << " ";
    }

    return 0;
}
