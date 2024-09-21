#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + 1 + length;
        }
        return result;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    string encoded = solution.encode(strs);
    cout << "Encoded: " << encoded << endl;

    vector<string> decoded = solution.decode(encoded);
    cout << "Decoded:" << endl;
    for (auto& str : decoded) {
        cout << str <<;
    }

    return 0;
}
