#include<bits/stdc++.h>
using namespace std;

vector<int> calculateMinCompressedLength(int n, int k, const string& s) {
    vector<int> results;

    for (int i = 0; i <= n - k; ++i) {
        string t = s.substr(i, k);
        int min_length = INT_MAX;

        for (int j = 1; j < k; j += 2) {
            int t1 = stoi(t.substr(0, j));
            string t2 = t.substr(j);
            int compressed_length = t2.length() * t1;
            min_length = min(min_length, compressed_length);
        }

        results.push_back(min_length);
    }

    return results;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> results = calculateMinCompressedLength(n, k, s);

    for (int result : results) {
        cout << result << " ";
    }
    cout << endl;

    return 0;
}
