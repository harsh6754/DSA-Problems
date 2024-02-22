#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";

        string result;
        vector<string> singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        vector<string> teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands = {"", "Thousand", "Million", "Billion"};

        for (int i = 0; num > 0; ++i) {
            if (num % 1000 != 0)
                result = helper(num % 1000, singles, teens, tens) + thousands[i] + " " + result;
            num /= 1000;
        }

        // Remove leading and trailing spaces
        while (result.back() == ' ')
            result.pop_back();
        return result;
    }

private:
    string helper(int num, vector<string>& singles, vector<string>& teens, vector<string>& tens) {
        string result;
        if (num >= 100) {
            result += singles[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            result += tens[num / 10] + " ";
            num %= 10;
        }
        if (num >= 10) {
            result += teens[num - 10] + " ";
            return result;
        }
        if (num > 0)
            result += singles[num] + " ";
        return result;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter a number: ";
    cin >> num;
    cout << sol.numberToWords(num) << endl;
    return 0;
}
