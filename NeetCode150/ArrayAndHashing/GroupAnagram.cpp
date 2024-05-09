#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> mp;
        vector<vector<int>> result;

        // Populate the unordered_map with the indices of words
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }

        // Check all possible combinations of prefixes and suffixes
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j <= words[i].size(); j++) {
                string prefix = words[i].substr(0, j);
                string suffix = words[i].substr(j);

                if (isPalindrome(prefix)) {
                    string revSuffix = suffix;
                    reverse(revSuffix.begin(), revSuffix.end());
                    if (mp.count(revSuffix) && mp[revSuffix] != i) {
                        result.push_back({mp[revSuffix], i});
                    }
                }

                if (!suffix.empty() && isPalindrome(suffix)) {
                    string revPrefix = prefix;
                    reverse(revPrefix.begin(), revPrefix.end());
                    if (mp.count(revPrefix) && mp[revPrefix] != i) {
                        result.push_back({i, mp[revPrefix]});
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter the words: ";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution solution;
    vector<vector<int>> result = solution.palindromePairs(words);
    
    cout << "Palindrome Pairs:" << endl;
    for (const auto& pair : result) {
        for (int index : pair) {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
