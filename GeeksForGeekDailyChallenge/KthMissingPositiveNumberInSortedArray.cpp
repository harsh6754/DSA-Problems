#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int KthPositiveMissingNumber(vector<int>& arr, int k) {
        int missingCount = 0, currentNum = 1, i = 0;
        while (true) {
            if (i < arr.size() && arr[i] == currentNum) {
                i++;
            } else {
                missingCount++;
                if (missingCount == k) {
                    return currentNum;
                }
            }
            currentNum++;
        }
        return -1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    Solution solution;
    int result = solution.KthPositiveMissingNumber(arr, k);
    cout << result;

    return 0;
}
