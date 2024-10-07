#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double fractionalKnapsack(int W, int N, vector<int>& values, vector<int>& weight) {
        vector<pair<double, int>> items(N);
        
        for (int i = 0; i < N; i++) {
            items[i] = { (double)values[i] / weight[i], i }; // value-to-weight ratio and index
        }
        
        sort(items.rbegin(), items.rend()); // sort in decreasing order of ratio

        double maxValue = 0.0;
        for (int i = 0; i < N; i++) {
            int idx = items[i].second;
            if (weight[idx] <= W) {
                maxValue += values[idx];
                W -= weight[idx];
            } else {
                maxValue += items[i].first * W;
                break;
            }
        }
        
        return maxValue;
    }
};

int main() {
    int N;
    cin >> N;

    int W;
    cin >> W;

    vector<int> values(N);
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    vector<int> weight(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    Solution solution;
    double result = solution.fractionalKnapsack(W, N, values, weight);
    cout << fixed << setprecision(6) << result;

    return 0;
}
