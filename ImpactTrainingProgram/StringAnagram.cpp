#include <iostream>
#include <algorithm>
using namespace std;

string are_anagrams(const string& str1, const string& str2) {
    string lower_str1 = str1;
    string lower_str2 = str2;
    transform(lower_str1.begin(), lower_str1.end(), lower_str1.begin(), ::tolower);
    transform(lower_str2.begin(), lower_str2.end(), lower_str2.begin(), ::tolower);

    // Sort the characters in each string
    sort(lower_str1.begin(), lower_str1.end());
    sort(lower_str2.begin(), lower_str2.end());

    // Check if the sorted strings are equal
    if (lower_str1 == lower_str2) {
        return "Anagram";
    } else {
        return "Not Anagram";
    }
}

int main() {
    // Input
    string string1, string2;
    cin >> string1 >> string2;

    // Output
    string result = are_anagrams(string1, string2);
    cout << result << endl;

    return 0;
}
