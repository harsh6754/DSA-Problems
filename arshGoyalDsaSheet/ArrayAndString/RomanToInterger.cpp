#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int result = 0;
        int prevValue = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            int value = romanMap[s[i]];
            
            if (value < prevValue) {
                result -= value;
            } else {
                result += value;
            }
            
            prevValue = value;
        }
        
        return result;
    }
};

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    Solution solution;
    int result = solution.romanToInt(romanNumeral);
    cout << "Integer representation: " << result << endl;

    return 0;
}
