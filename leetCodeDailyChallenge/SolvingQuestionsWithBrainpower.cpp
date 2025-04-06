#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            int point = questions[i][0];
            int brain = questions[i][1];
            long long skip = dp[i + 1];
            long long solve = point + (i + brain + 1 < n ? dp[i + brain + 1] : 0);
            dp[i] = max(solve, skip);
        }

        return dp[0];
    }
};

int main() {
    int n;
    cout << "Enter number of questions: ";
    cin >> n;

    vector<vector<int>> questions(n, vector<int>(2));
    cout << "Enter each question in format [points brainpower]:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Question " << i + 1 << ": ";
        cin >> questions[i][0] >> questions[i][1];
    }

    Solution sol;
    long long result = sol.mostPoints(questions);

    cout << "Maximum points you can earn: " << result << endl;

    return 0;
}
