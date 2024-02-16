#include <iostream>
#include <vector>
#include <climits>

using namespace std;

string minWindow(string s, string t) {
    vector<int> target_counts(128, 0); // Assuming ASCII characters
    vector<int> window_counts(128, 0);

    // Count characters in string t
    for (char c : t) {
        target_counts[c]++;
    }

    int left = 0, right = 0;
    int min_len = INT_MAX;
    int min_left = 0;
    int formed_chars = 0;
    int required_chars = t.length();

    while (right < s.length()) {
        // Expand the window
        window_counts[s[right]]++;
        if (window_counts[s[right]] <= target_counts[s[right]]) {
            formed_chars++;
        }

        // Try to minimize the window
        while (formed_chars == required_chars) {
            if (right - left + 1 < min_len) {
                min_len = right - left + 1;
                min_left = left;
            }

            window_counts[s[left]]--;
            if (window_counts[s[left]] < target_counts[s[left]]) {
                formed_chars--;
            }
            left++;
        }
        right++;
    }

    return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
}

int main() {
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    cout << "Minimum window substring: " << minWindow(s, t) << endl;

    return 0;
}
