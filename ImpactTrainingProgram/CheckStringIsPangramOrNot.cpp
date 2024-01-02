#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkPangram(const string& str) {
    vector<bool> mark(26, false);

    for (char ch : str) {
        if (isalpha(ch)) {
            int index = tolower(ch) - 'a';
            mark[index] = true;
        }
    }

    return all_of(mark.begin(), mark.end(), [](bool val) { return val; });
}

int main() {
    string str;
    getline(cin, str);

    if (checkPangram(str)) {
        cout << "Pangram" << endl;
    } else {
        cout << "Not a Pangram" << endl;
    }

    return 0;
}
