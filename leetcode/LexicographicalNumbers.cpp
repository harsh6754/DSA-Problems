#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(int cur, int n, vector<int> &ans) {
        if (cur > n) {
            return;
        }
        ans.push_back(cur);
        for (int i = 0; i <= 9; i++) {
            helper(cur * 10 + i, n, ans);
        }
    }
    
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            helper(i, n, ans);
        }
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the Value of N: ";
    cin >> n;

    Solution solution;
    vector<int> result = solution.lexicalOrder(n);

    // Printing the result
    cout << "Lexicographically ordered numbers up to " << n << " are:" << endl;
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
