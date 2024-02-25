#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertAtRightPlace(stack<int> &st, int x) {
        if (st.empty() || x > st.top()) {
            st.push(x);
            return;
        }
        int topElement = st.top();
        st.pop();
        insertAtRightPlace(st, x);
        st.push(topElement);
    }

    void SortedStack(stack<int> &st) {
        if (st.empty())
            return;

        int topElement = st.top();
        st.pop();

        SortedStack(st);

        insertAtRightPlace(st, topElement);
    }
};

int main() {
    stack<int> st;

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        st.push(x);
    }

    Solution solution;
    solution.SortedStack(st);

    cout << "Sorted Stack: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
