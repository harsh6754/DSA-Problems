#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> result;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == i) continue;
                for (int k = 0; k < n; ++k) {
                    if (k == i || k == j) continue;
                    int a = digits[i], b = digits[j], c = digits[k];
                    if (a == 0) continue; // no leading zero
                    if (c % 2 != 0) continue; // must be even
                    int num = a * 100 + b * 10 + c;
                    result.insert(num);
                }
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};

int main() {
    int n;
    cout << "Enter number of digits: ";
    cin >> n;
    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int i = 0; i < n; ++i) {
        cin >> digits[i];
    }
    Solution sol;
    vector<int> res = sol.findEvenNumbers(digits);
    cout << "Unique three-digit even numbers: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}