#include <bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int i, int j) {
    if(i < 0 || j < 0) return 0;

    if(s1[i] == s2[j])
        return 1 + LCS(s1, s2, i-1, j-1);

    return max(LCS(s1, s2, i-1, j), LCS(s1, s2, i, j-1));
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << LCS(s1, s2, s1.size()-1, s2.size()-1);
}
