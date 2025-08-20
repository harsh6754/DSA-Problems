#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<string> ans;
    void gen(string& cur, int open, int close, int n){
        if(cur.size() == 2*n){ ans.push_back(cur); return; }
        if(open < n){
            cur.push_back('(');
            gen(cur, open+1, close, n);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            gen(cur, open, close+1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n){
        ans.clear();
        string cur;
        gen(cur, 0, 0, n);
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Solution s;
    auto v = s.generateParenthesis(n);
    for(auto &x : v) cout << x << "\n";
    return 0;
}
