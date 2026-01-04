#include <bits/stdc++.h>
using namespace std;

long long valueOfRes(vector<int> &res) {
    long long ans = 0;
    int prefixXOR = 0;
    
    for(int x : res){
        prefixXOR ^= x;
        ans += prefixXOR;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    long long maxValue = 0;

    // Try starting from each index
    for(int start = 0; start < n; start++) {
        
        // ---- Move Right (clockwise) ----
        vector<int> res;
        int idx = start;
        for(int k = 0; k < n; k++) {
            res.push_back(arr[idx]);
            idx = (idx + 1) % n;
        }
        maxValue = max(maxValue, valueOfRes(res));

        // ---- Move Left (anti-clockwise) ----
        res.clear();
        idx = start;
        for(int k = 0; k < n; k++) {
            res.push_back(arr[idx]);
            idx = (idx - 1 + n) % n;
        }
        maxValue = max(maxValue, valueOfRes(res));
    }

    cout << maxValue;
    return 0;
}
