#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string nearestPalindromic(string n) {
        long originalNumber = stol(n);
        long closestPalindrome = -1;

        for (long candidate : getCandidates(n, originalNumber)) {
            if (closestPalindrome == -1 || 
                abs(candidate - originalNumber) < abs(closestPalindrome - originalNumber) ||
                (abs(candidate - originalNumber) == abs(closestPalindrome - originalNumber) && candidate < closestPalindrome)) {
                closestPalindrome = candidate;
            }
        }
        return to_string(closestPalindrome);
    }

    unordered_set<long> getCandidates(string& n, long originalNumber) {
        int length = n.size();
        unordered_set<long> candidates;

        candidates.insert((long) pow(10, length - 1) - 1);
        candidates.insert((long) pow(10, length) + 1);

        long firstHalf = stol(n.substr(0, (length + 1) / 2));
        for (long i = firstHalf - 1; i <= firstHalf + 1; ++i) {
            string prefix = to_string(i);

            string candidate = prefix + string(prefix.rbegin() + (length & 1), prefix.rend());

            candidates.insert(stol(candidate));
        }

        candidates.erase(originalNumber);

        return candidates;
    }
};

int main() {
    string n;
    getline(cin, n);

    Solution solution;
    string result = solution.nearestPalindromic(n);
    cout << result;

    return 0;
}
