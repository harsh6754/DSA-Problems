#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;    
        stack<string> resultStack;  
        string result = "";
        int index = 0;

        while (index < s.length()) {
            if (isdigit(s[index])) {
                int count = 0;
                while (isdigit(s[index])) {
                    count = count * 10 + (s[index] - '0');
                    index++;
                }
                countStack.push(count);
            } else if (s[index] == '[') {
                resultStack.push(result);
                result = "";
                index++;
            } else if (s[index] == ']') {
                string temp = result;
                result = resultStack.top();
                resultStack.pop();
                int count = countStack.top();
                countStack.pop();
                for (int i = 0; i < count; i++) {
                    result += temp;
                }
                index++;
            } else {
                result += s[index];
                index++;
            }
        }
        return result;
    }
};

int main() {
    string s;
    getline(cin, s);

    Solution solution;
    string result = solution.decodeString(s);
    cout << result;

    return 0;
}
