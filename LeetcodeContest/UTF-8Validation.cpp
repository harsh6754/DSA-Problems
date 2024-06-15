#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nextRBytes = 0;
        for (auto x : data) {
            if (nextRBytes == 0) {
                if ((x >> 5) == 0b110) {
                    nextRBytes = 1;
                }
                else if ((x >> 4) == 0b1110) {
                    nextRBytes = 2;
                }
                else if ((x >> 3) == 0b11110) {
                    nextRBytes = 3;
                }
                else if ((x >> 7) != 0b0) {
                    return false;
                }
            } else {
                if ((x >> 6) != 0b10) {
                    return false;
                }
                nextRBytes--;
            }
        }
        return nextRBytes == 0;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    Solution solution;
    bool result = solution.validUtf8(data);
    cout<<result ? 0 : 1;
    return 0;
}
