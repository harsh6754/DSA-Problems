//682 Baseball Game
// Leetcode
//Easy
// Uber 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (auto &op : operations) {
            if (op == "C") {
                scores.pop_back();
            } else if (op == "D") {
                scores.push_back(scores.back() * 2);
            } else if (op == "+") {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            } else {
                scores.push_back(stoi(op));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> operations(n);
    for (int i = 0; i < n; i++) {
        cin >> operations[i];
    }
    Solution sol;
    cout << sol.calPoints(operations);
}
