#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char flip(char ch) {
        return (ch == '0') ? '1' : '0';
    }

    void complement(string str) {
        int length = str.length();
        string ones, twos;

        // Calculate one's complement
        for (int i = 0; i < length; i++) {
            ones += flip(str[i]);
        }

        // Calculate two's complement
        twos = ones;
        for (int i = length - 1; i >= 0; i--) {
            if (ones[i] == '1') {
                twos[i] = '0';
            } else {
                twos[i] = '1';
                break;
            }
        }

        // If all bits were '1', add a leading '1' to two's complement
        if (twos.find('1') == string::npos) {
            twos = '1' + twos;
        }

        // Output results
        cout << "One's Complement: " << ones << endl;
        cout << "Two's Complement: " << twos << endl;
    }
};

int main() {
    string str;
    cout << "Enter a binary string: ";
    getline(cin, str);

    Solution solution;
    solution.complement(str);

    return 0;
}
