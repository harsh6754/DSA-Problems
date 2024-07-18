#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int A, int B) {
        vector<int> ans;
        for (int i = A; i <= B; i++) {
            if (i % 7 == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    int A, B;
    cin >> A >> B;

    Solution solution;
    vector<int> result = solution.solve(A, B);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
