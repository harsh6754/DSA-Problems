#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &inputStack, int count, int size) {
    if (count == size / 2) {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();

    solve(inputStack, count + 1, size);
    inputStack.push(num);
}

void deleteMiddle(stack<int> &inputStack, int N) {
    int count = 0;
    solve(inputStack, count, N);
}
int main()
{
    int n;
    cin >> n;

    stack<int> inputStack;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        inputStack.push(num);
    }
    stack<int> tempStack = inputStack;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    deleteMiddle(inputStack, n);
    while (!inputStack.empty())
    {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;
    return 0;
}