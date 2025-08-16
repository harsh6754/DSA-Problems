#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Cartesian product of two sets
    set<string> product(set<string>& A, set<string>& B) {
        if (A.empty()) return B;
        if (B.empty()) return A;
        set<string> result;
        for (auto &x : A)
            for (auto &y : B)
                result.insert(x + y);
        return result;
    }

    // DFS parser
    set<string> dfs(string &expr, int &i) {
        set<string> res;     // union result
        set<string> cur;     // current concatenation
        cur.insert("");

        while (i < expr.size() && expr[i] != '}') {
            if (expr[i] == '{') {
                i++; // skip '{'
                set<string> sub = dfs(expr, i); // expand inside braces
                cur = product(cur, sub);
            } 
            else if (expr[i] == ',') {
                // union operation
                res.insert(cur.begin(), cur.end());
                cur.clear();
                cur.insert("");
                i++;
            } 
            else { // normal letter
                string s(1, expr[i]);
                set<string> single = {s};
                cur = product(cur, single);
                i++;
            }
        }

        // merge last cur into result
        res.insert(cur.begin(), cur.end());

        if (i < expr.size() && expr[i] == '}') i++; // ✅ FIX: move past '}'

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = dfs(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main() {
    Solution sol;
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    vector<string> result = sol.braceExpansionII(expr);

    cout << "Expanded results:\n";
    for (auto &s : result) cout << s << " ";
    cout << "\n";
    return 0;
}
