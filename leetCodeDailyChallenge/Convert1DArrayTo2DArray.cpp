#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    if (original.size() != m * n) {
        return {};
    }
    vector<vector<int>> result(m, vector<int>(n));
    for (int i = 0; i < original.size(); ++i) {
        result[i / n][i % n] = original[i];
    }
    
    return result;
}

int main() {
    int n, m, col_size;
    cin >> n;
    cin >> m >> col_size;

    vector<int> original(n);
    for (int i = 0; i < n; i++) {
        cin >> original[i];
    }

    vector<vector<int>> result = construct2DArray(original, m, col_size);

    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
