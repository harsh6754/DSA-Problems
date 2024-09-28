#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq_map;
        // Count frequency of each character
        for (char c : s) {
            freq_map[c]++;
        }

        // Use a max-heap to store characters by frequency
        priority_queue<pair<int, char>> max_heap;
        for (auto& entry : freq_map) {
            max_heap.push({entry.second, entry.first});
        }

        // Build the result string
        string ans = "";
        while (!max_heap.empty()) {
            auto [freq, ch] = max_heap.top();
            max_heap.pop();
            ans += string(freq, ch);  // Append character freq times
        }

        return ans;
    }
};

int main() {
    string s;
    getline(cin, s);  // Input the string

    Solution solution;
    string result = solution.frequencySort(s);
    cout << result;

    return 0;
}
