#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            
            if (bit_c == 0) {
                flips += bit_a + bit_b;
            } else {
                if (bit_a == 0 && bit_b == 0) {
                    flips += 1;
                }
            }
        }
        return flips;
    }
};

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    Solution solution;
    int result = solution.minFlips(a, b, c);
    cout << result;

    return 0;
}
