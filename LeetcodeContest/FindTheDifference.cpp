#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        char findTheDifference(string s, string t) {
            unordered_map<char, int> count;
            for(char c : t) {
                count[c]++;
            }
            for(char c : s) {
                count[c]--;
            }
            for(auto it : count) {
                if(it.second > 0) {
                    return it.first;
                }
            }
            return '\0'; 
        }
};

int main() {
    string s;
    cin >> s;

    string t;
    cin >> t;

    Solution solution;
    char result = solution.findTheDifference(s, t);
    cout << result << endl;

    return 0;
}
