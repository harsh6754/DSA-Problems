#include <iostream>
#include <string>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int longestString(const string &s) {
    int len = s.length();
    int start = 0, end = len - 1;
    while (start < len && isVowel(s[start])) ++start;
    while (end >= 0 && isVowel(s[end])) --end;
    if (start >= len) return len;
    int res = start + len - 1 - end;
    int longest = 0, sum = 0;
    for (int i = start + 1; i <= end; ++i) {
        if (isVowel(s[i]))
            ++sum;
        else
            sum = 0;
        longest = max(sum, longest);
    }
    return longest + res;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "Longest modified string length: " << longestString(s) << endl;
    return 0;
}
