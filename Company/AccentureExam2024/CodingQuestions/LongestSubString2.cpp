#include <iostream>
#include <string>
using namespace std;

int longestContinuousSubstringLength(const string& str) {
    if (str.empty()) return 0;

    int max_length = 1; // To store the maximum length of continuous substring
    int current_length = 1; // To track the current continuous substring length

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            current_length++; // Increment if the current character matches the previous
        } else {
            max_length = max(max_length, current_length); // Update the max length
            current_length = 1; // Reset the current length
        }
    }

    // Ensure to update max_length for the last substring
    max_length = max(max_length, current_length);

    return max_length;
}

int main() {
    string str = "aaabbcccccddddee";
    int result = longestContinuousSubstringLength(str);
    cout << "Longest continuous substring length: " << result << endl;
    return 0;
}
