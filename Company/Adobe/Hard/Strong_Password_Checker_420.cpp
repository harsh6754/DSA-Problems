#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        
        int missing = getMissing(password);

        int replaces = 0; 
        int oneSeq = 0;   
        int twoSeq = 0;   

        for (int i = 2; i < n;) {
            if (i < n && password[i] == password[i - 1] && password[i - 1] == password[i - 2]) {
                int length = 2;
                while (i < n && password[i] == password[i - 1]) {
                    length++;
                    i++;
                }
                replaces += length / 3;
                if (length % 3 == 0) oneSeq++;
                else if (length % 3 == 1) twoSeq++;
            } else {
                i++;
            }
        }

        if (n < 6) return max(6 - n, missing);
        else if (n <= 20) return max(replaces, missing);

        int deletes = n - 20;
        replaces -= min(oneSeq, deletes);
        replaces -= min(max(deletes - oneSeq, 0), twoSeq * 2) / 2;
        replaces -= max(deletes - oneSeq - twoSeq * 2, 0) / 3;

        return deletes + max(replaces, missing);
    }

private:
    int getMissing(const string& s) {
        bool lower = false, upper = false, digit = false;
        for (char c : s) {
            if (islower(c)) lower = true;
            else if (isupper(c)) upper = true;
            else if (isdigit(c)) digit = true;
        }
        return (!lower) + (!upper) + (!digit);
    }
};

int main() {
    string password;
    cout << "Enter password: ";
    cin >> password;

    Solution sol;
    int result = sol.strongPasswordChecker(password);

    cout << "Minimum steps to make the password strong: " << result << endl;
    return 0;
}
