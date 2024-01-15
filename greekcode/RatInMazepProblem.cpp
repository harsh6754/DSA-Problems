#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool possible(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited) {
        if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        } else {
            return false;
        }
    }

    void solve(vector<vector<int>> m, int n, vector<vector<int>> visited, string path, vector<string>& ans,
               int x, int y) {
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;
        int newx = x + 1;
        int newy = y;
        if (possible(newx, newy, m, n, visited)) {
            path.push_back('D');
            solve(m, n, visited, path, ans, newx, newy);
            path.pop_back();
        }

        newx = x;
        newy = y - 1;
        if (possible(newx, newy, m, n, visited)) {
            path.push_back('L');
            solve(m, n, visited, path, ans, newx, newy);
            path.pop_back();
        }
        newx = x - 1;
        newy = y;
        if (possible(newx, newy, m, n, visited)) {
            path.push_back('U');
            solve(m, n, visited, path, ans, newx, newy);
            path.pop_back();
        }
        newx = x;
        newy = y + 1;
        if (possible(newx, newy, m, n, visited)) {
            path.push_back('R');
            solve(m, n, visited, path, ans, newx, newy);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans;

        if (m[0][0] == 0) {
            return ans;
        }

        int xind = 0;
        int yind = 0;

        vector<vector<int>> visited = m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }

        string path = "";

        solve(m, n, visited, path, ans, xind, yind);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));

    cout << "Enter the matrix elements (0 for blocked path, 1 for open path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    Solution obj;
    vector<string> result = obj.findPath(matrix, n);

    if (result.empty()) {
        cout << "No valid paths found." << endl;
    } else {
        cout << "Valid paths:" << endl;
        for (const string& path : result) {
            cout << path << " ";
        }
        cout << endl;
    }

    return 0;
}
