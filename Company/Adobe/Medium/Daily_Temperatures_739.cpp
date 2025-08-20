#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        stack<int> st; // indices store karenge

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int idx = st.top();
                st.pop();
                answer[idx] = i - idx; // kitne din baad zyada temperature mila
            }
            st.push(i);
        }
        return answer;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    Solution solution;
    vector<int> result = solution.dailyTemperatures(temperatures);
    for (auto &i : result) {
        cout << i << " ";
    }

    return 0;
}
