#include <iostream>
#include <string>
using namespace std;

int findLongestEvenLengthSubstring(const string& s) {
    int n = s.length();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 2; j < n; j += 2) {
            string currentSubstring = s.substr(i, j - i + 1);
            
            int halfLength = (j - i + 1) / 2;
            string leftHalf = currentSubstring.substr(0, halfLength);
            string rightHalf = currentSubstring.substr(halfLength);

            int leftSum = 0, rightSum = 0;
            for (char c : leftHalf) {
                leftSum += c - '0';
            }
            for (char c : rightHalf) {
                rightSum += c - '0';
            }

            if (leftSum == rightSum && j - i + 1 > maxLength) {
                maxLength = j - i + 1;
            }
        }
    }

    return maxLength;
}

int main() {
    string input;
    cout << "Enter a string of digits: ";
    cin >> input;

    int longestEvenLengthSubstring = findLongestEvenLengthSubstring(input);

    if (longestEvenLengthSubstring == 0) {
        cout << "No even-length substring with the specified condition found." << endl;
    } else {
        cout << "Length of the longest even-length substring: " << longestEvenLengthSubstring << endl;
    }

    return 0;
}
