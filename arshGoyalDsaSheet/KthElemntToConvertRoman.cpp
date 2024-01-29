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

    string kthValueToRoman(vector<vector<int>>& nums, int k) {
        int n = nums.size();
        int m = nums[0].size();

        if (k > n * m || k <= 0) {
            return "Invalid";
        }

        int row = (k - 1) / m;
        int col = (k - 1) % m;

        return intToRoman(nums[row][col]);
    }
};

int main() {
    int numRows, numCols, k;
    cout << "Enter the number of rows and columns: ";
    cin >> numRows >> numCols;

    vector<vector<int>> nums(numRows, vector<int>(numCols));

    cout << "Enter the elements of the 2D array:\n";
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            cin >> nums[i][j];
        }
    }

    cout << "Enter the value of K: ";
    cin >> k;

    Solution solution;
    string romanValue = solution.kthValueToRoman(nums, k);
    cout << "Roman representation of the Kth value: " << romanValue << endl;

    return 0;
}
