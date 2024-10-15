#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& costs, int n) {
        // Edge cases for 1 or 2 steps
        if (n == 1) return costs[0];
        if (n == 2) return min(costs[0], costs[1]);

        int prev2 = costs[0]; // Cost to reach step 0
        int prev1 = costs[1]; // Cost to reach step 1

        // Loop through steps from 2 to n-1
        for (int i = 2; i < n; i++) {
            int current = costs[i] + min(prev1, prev2);
            prev2 = prev1; // Move forward in steps
            prev1 = current;
        }

        // The result is the minimum cost to reach the last step
        return min(prev1, prev2);
    }

    int minCostToClimbingStair(vector<int>& costs) {
        int size = costs.size();
        return solve(costs, size);
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> costs(n);
    for (int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    Solution solution;
    int result = solution.minCostToClimbingStair(costs);
    cout << result;

    return 0;
}
