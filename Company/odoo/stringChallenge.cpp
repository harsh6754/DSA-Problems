#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    int i;
    cin >> s >> i;

    if (i < s.size()) {
        s[i] = toupper(s[i]);
    }

    int n = s.size();
    s[n-1] = toupper(s[n-1]);

    cout << s << endl;
    return 0;
}
