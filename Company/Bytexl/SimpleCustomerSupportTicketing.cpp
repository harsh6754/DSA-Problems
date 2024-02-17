#include <iostream>
#include <stack>
#include <string>

using namespace std;

string isBalanced(string s) {
    stack<char> str;
    string ans = "YES";
    string no = "NO";
    bool answer = true;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch == '{' || ch == '[' || ch == '(') {
            str.push(ch);
            continue;
        }
        if (str.empty()) {
            return no;
        }
        if (ch == ')') {
            if (str.top() == '(') {
                str.pop();
            } else {
                answer = false;
                break;
            }
        }
        if (ch == ']') {
            if (str.top() == '[') {
                str.pop();
            } else {
                answer = false;
                break;
            }
        }
        if (ch == '}') {
            if (str.top() == '{') {
                str.pop();
            } else {
                answer = false;
                break;
            }
        }
    }
    if (!str.empty()) {
        answer = false;
    }
    if (answer) {
        return ans;
    } else {
        return no;
    }
}

int main() {
    string s;
    cin >> s;

    string result = isBalanced(s);
    cout <<result << endl;

    return 0;
}
