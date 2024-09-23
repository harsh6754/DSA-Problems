#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> ss(dictionary.begin(), dictionary.end());
        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                if (ss.count(s.substr(j, i - j))) {
                    f[i] = min(f[i], f[j]);
                }
            }
        }
        return f[n];
    }
};
int main(){
    string s;
    getline(cin,s);

    int n;
    cin>>n;

    vector<string>dictionary(n);
    for(int i = 0;i<n;i++){
        cin>>dictionary[i];
    }

    Solution solution;
    int result = solution.minExtraChar(s,dictionary);
    cout<<result;

    return 0;
}