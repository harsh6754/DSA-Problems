#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getPalindromesInRange(int lower, int upper) {
        vector<int> palindromes; // To store all palindromes
        for (int i = lower; i <= upper; i++) {
            int num = i, rev = 0;
            while (num != 0) {
                int rem = num % 10;
                rev = rev * 10 + rem;
                num = num / 10;
            }
            if (rev == i) { // Check if the number is a palindrome
                palindromes.push_back(i);
            }
        }
        return palindromes;
    }
};

int main() {
    int lower, upper;
    cin >> lower >> upper;

    Solution solution;
    vector<int> palindromes = solution.getPalindromesInRange(lower, upper);

    for (int palindrome : palindromes) {
        cout << palindrome << " ";
    }
    cout << endl;

    return 0;
}
