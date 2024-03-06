#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right && s[left] == s[right]) {
            char ch = s[left];
            while (left <= right && s[left] == ch) {
                left++;
            }
            while (right >= left && s[right] == ch) {
                right--;
            }
        }

        return right - left + 1;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution obj;
    int result = obj.minimumLength(s);
    cout << "Minimum length of non-empty string after performing all possible erasures: " << result << endl;

    return 0;
}
