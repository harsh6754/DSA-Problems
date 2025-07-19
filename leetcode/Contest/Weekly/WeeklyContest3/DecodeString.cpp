#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for(char ch : s) {
            if(isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if(ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if(ch == ']') {
                string decoded = stringStack.top(); stringStack.pop();
                int repeatCount = countStack.top(); countStack.pop();
                for(int i = 0; i < repeatCount; i++) {
                    decoded += currentString;
                }
                currentString = decoded;
            } else {
                currentString += ch;
            }
        }
        return currentString;
    }
};

int main() {
    string s;
    cin >> s;
    
    Solution sol;
    cout << sol.decodeString(s) << endl;
    return 0;
}
