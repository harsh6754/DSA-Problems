#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumSteps(string s) {
        int white = 0; // Count of '1's encountered
        int res = 0;   // Resulting count of steps
        int n = s.length();

        for (int j = 0; j < n; j++) {
            if (s[j] == '0') {
                res += white; // Add the count of '1's for every '0'
            }
            if (s[j] == '1') {
                white++; // Increment count for '1'
            }
        }

        return res;
    }
};

int main() {
    string s;
    cin >> s; // Input the binary string

    Solution solution;
    int result = solution.minimumSteps(s);
    cout << result << endl; // Output the result

    return 0;
}
