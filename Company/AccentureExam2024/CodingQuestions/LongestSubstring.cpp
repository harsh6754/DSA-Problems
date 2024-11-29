#include <iostream>
#include <string>
using namespace std;

int longestContinuousSubstringLength(const string& str) {
    if (str.empty()) return 0;

    int max_length = 1; // To store the maximum length of continuous substring
    int current_length = 1; // To track the current continuous substring length

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1] + 1) { // Check if characters are in lexicographical order
            current_length++;
        } else {
            max_length = max(max_length, current_length); // Update max length
            current_length = 1; // Reset the current length
        }
    }

    // Ensure to update max_length for the last substring
    max_length = max(max_length, current_length);

    return max_length;
}

int main() {
    string str = "abcdexyzabcmnop";
    int result = longestContinuousSubstringLength(str);
    cout << "Longest continuous substring length: " << result << endl;
    return 0;
}
