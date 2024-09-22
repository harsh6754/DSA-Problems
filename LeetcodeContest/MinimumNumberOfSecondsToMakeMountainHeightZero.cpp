#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        auto canComplete = [&](long long time) -> bool {
            long long totalWork = 0;
            for (int t : workerTimes) {
                long long lo = 0, hi = mountainHeight;
                while (lo < hi) {
                    long long mid = lo + (hi - lo + 1) / 2;
                    if (t * mid * (mid + 1) / 2 <= time)
                        lo = mid;
                    else
                        hi = mid - 1;
                }
                totalWork += lo;
                if (totalWork >= mountainHeight) return true;
            }
            return totalWork >= mountainHeight;
        };
        long long left = 1, right = 1e18, answer = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (canComplete(mid)) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
};

int main() {
    int mountainHeight;
    cin >> mountainHeight;

    int n;
    cin >> n;

    vector<int> workerTimes(n);
    for (int i = 0; i < n; i++) {
        cin >> workerTimes[i];
    }

    Solution solution;
    long long result = solution.minNumberOfSeconds(mountainHeight, workerTimes);
    cout << result;
    return 0;
}