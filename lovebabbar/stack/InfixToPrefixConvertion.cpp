
#include<bits/stdc++.h>
using namespace std;

class StackWrapper {
    stack<char> st;

public:
    char peekwrap() {
        if (!st.empty()) {
            return st.top();
        } else {
            return '~';
        }
    }

    void pushwrap(char ch) {
        st.push(ch);
    }

    char popwrap() {
        char top = st.top();
        st.pop();
        return top;
    }
};

int main() {
    string input;
    cin >> input;

    std::string reversedInput(input.rbegin(), input.rend());

    StackWrapper st;
    string prefix = "";

    for (char ch : reversedInput) {
        if (st.peekwrap() == '~') {
            // Stack is empty
            if (ch == ')' || ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^') {
                st.pushwrap(ch);
            } else {
                prefix += ch;
            }
        } else {
            if (ch == ')') {
                st.pushwrap(ch);
            } else if (ch == '(') {
                while (st.peekwrap() != ')') {
                    prefix += st.popwrap();
                }
                st.popwrap();
            } else if (ch == '^') {
                st.pushwrap(ch);
            } else if (ch == '+' || ch == '-') {
                while (st.peekwrap() == '^' || st.peekwrap() == '*' || st.peekwrap() == '/') {
                    prefix += st.popwrap();
                }
                st.pushwrap(ch);
            } else if (ch == '/' || ch == '*') {
                while (st.peekwrap() == '*') {
                    prefix += st.popwrap();
                }
                st.pushwrap(ch);
            } else {
                prefix += ch;
            }
        }
    }

    while (st.peekwrap() != '~') {
        prefix += st.popwrap();
    }


   reverse(prefix.begin(), prefix.end());

    cout << prefix <<endl;

    return 0;
}