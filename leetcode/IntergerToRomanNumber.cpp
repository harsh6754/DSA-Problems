#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> integer_values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman_numerals = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string result = "";
        for (int i = 0; i < integer_values.size(); i++) {
            while (num >= integer_values[i]) {
                result += roman_numerals[i];
                num -= integer_values[i];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int num = 1994;
    string roman = sol.intToRoman(num);
    cout << "The Roman numeral for " << num << " is " << roman << endl;
    return 0;
}
