#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int numMagicSquaresInside(vector<vector<int>>& grid) {
            int rows_size = grid.size();
            int cols_size = grid[0].size();
            int ans = 0;

            auto check = [&](int i, int j) -> int {
                if (i + 3 > rows_size || j + 3 > cols_size) {
                    return 0;
                }

                vector<int> cnt(10);
                vector<int> row(3), col(3);
                int a = 0, b = 0;

                for (int x = i; x < i + 3; ++x) {
                    for (int y = j; y < j + 3; ++y) {
                        int v = grid[x][y];
                        
                        if (v < 1 || v > 9 || ++cnt[v] > 1) {
                            return 0;
                        }
                        
                        row[x - i] += v;
                        col[y - j] += v;
                        
                        if (x - i == y - j) {
                            a += v;
                        }
                        
                        if (x - i + y - j == 2) {
                            b += v;
                        }
                    }
                }

                if (a != b) {
                    return 0;
                }

                for (int k = 0; k < 3; ++k) {
                    if (row[k] != a || col[k] != a) {
                        return 0;
                    }
                }

                return 1;
            };

            for (int i = 0; i <= rows_size - 3; ++i) {
                for (int j = 0; j <= cols_size - 3; ++j) {
                    ans += check(i, j);
                }
            }

            return ans;
        }
};

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<int>> grid(row, vector<int>(col));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }

    Solution solution;
    int result = solution.numMagicSquaresInside(grid);
    cout << result;

    return 0;
}
