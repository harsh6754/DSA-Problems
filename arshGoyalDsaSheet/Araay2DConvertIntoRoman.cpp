#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string ths[] = {"", "M", "MM", "MMM"};

        return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }

    void convertAndPrintRoman(vector<vector<int>>& nums) {
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0; j < nums[i].size(); ++j) {
                cout << intToRoman(nums[i][j]) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numRows, numCols;
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numCols;

    vector<vector<int>> nums(numRows, vector<int>(numCols));

    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> nums[i][j];
        }
    }

    Solution solution;
    cout << "Roman representation of the 2D array:\n";
    solution.convertAndPrintRoman(nums);

    return 0;
}
