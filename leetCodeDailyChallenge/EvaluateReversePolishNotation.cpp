#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
private:
    long resolves(int a, int b, char Operator) {
        if (Operator == '+') return a + b;
        else if (Operator == '-') return a - b;
        else if (Operator == '*') return (long)a * b;
        return a / b;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> Stack;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            if (tokens[i].size() == 1 && !isdigit(tokens[i][0])) {
                long integer2 = Stack.top();
                Stack.pop();
                long integer1 = Stack.top();
                Stack.pop();
                
                char Operator = tokens[i][0];
                long resolvedAns = resolves(integer1, integer2, Operator);
                Stack.push(resolvedAns);
            } else {
                Stack.push(stol(tokens[i]));
            }
        }
        return Stack.top();
    }
};

int main() {
    Solution solution;
    vector<string> tokens;
    string token;
    
    cout << "Enter the RPN expression tokens separated by spaces (e.g., 2 1 + 3 *): ";
    while (cin >> token) {
        tokens.push_back(token);
    }

    cout << "Result: " << solution.evalRPN(tokens) << endl;
    
    return 0;
}
