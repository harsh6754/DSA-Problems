#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int FindAutoCount(const string &n) {
    if (n.empty()) {
        return 0;
    }

    int length = n.size();
    for (int i = 0; i < length; ++i) {
        int count = 0;
        for (char c : n) {
            if (c - '0' == i) {
                count++;
            }
        }
        if (n[i] - '0' != count) {
            return 0;
        }
    }
    unordered_set<char> distinct_digits(n.begin(), n.end());
    return distinct_digits.size();
}

int main() {
    string n;
    cout << "Enter the number: ";
    cin >> n;

    int result = FindAutoCount(n);

    if (result == 0) {
        cout << "The number is not autobiographical." << endl;
    } else {
        cout << "The number is autobiographical. Count of distinct digits: " << result << endl;
    }

    return 0;
}
