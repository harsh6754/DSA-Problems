#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isIsomorphic(string s, string t) {
            if (s.length() != t.length()) {
                return false;
            }

            unordered_map<char, char> s_to_t;
            unordered_map<char, char> t_to_s;

            for (int i = 0; i < s.length(); i++) {
                char char_s = s[i];
                char char_t = t[i];

                if (s_to_t.find(char_s) != s_to_t.end()) {
                    if (s_to_t[char_s] != char_t) {
                        return false;
                    }
                } else if (t_to_s.find(char_t) != t_to_s.end()) {
                    return false;
                } else {
                    s_to_t[char_s] = char_t;
                    t_to_s[char_t] = char_s;
                }
            }

            return true;
        }
};

int main(){
    string s;
    string t;
    getline(cin,s);
    getline(cin,t);

    Solution solution;
    bool result = solution.isIsomorphic(s,t);
    cout<<result ? 1 : 0;

    return 0;
}