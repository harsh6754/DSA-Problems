
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solutions(vector<int>& numbers) {
        int n = numbers.size();
        if (n <= 1) return 0;

        int exclude1 = numbers[0];
        int exclude2 = numbers[1];
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
            freq[numbers[i]]++;
        }

        int count = 0;
        for (auto& entry : freq) {
            int num = entry.first;
            if (num != exclude1 && num != exclude2) {
                count += entry.second;
            }
        }

        return count;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    Solution solution;
    int result = solution.solutions(numbers);
    cout << result;
    return 0;
}
