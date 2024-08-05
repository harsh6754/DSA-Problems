#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for (auto &x : arr) {
            mp[x]++;
        }
        for (auto &i : arr) {
            if (mp[i] == 1) {
                --k;
                if (k == 0) return i;
            }
        }
        return "";
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    Solution solution;
    string result = solution.kthDistinct(arr, k);
    cout << result;

    return 0;
}