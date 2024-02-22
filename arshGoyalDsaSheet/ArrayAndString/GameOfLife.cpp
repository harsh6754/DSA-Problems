#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNeighbours(const vector<vector<int>>& board, int row, int col) {
        int n = board.size();
        int m = board[0].size();
        int delrow[8] = {0, 1, 0, -1, 1, 1, -1, -1};
        int delcol[8] = {1, 0, -1, 0, -1, 1, 1, -1};
        int count = 0;

        for (int i = 0; i < 8; i++) {
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && board[nrow][ncol] == 1) {
                count++;
            }
        }

        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> nextBoard = board;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int neighbours = countNeighbours(board, i, j);

                if ((neighbours < 2 || neighbours > 3) && board[i][j] == 1) {
                    nextBoard[i][j] = 0;
                } else if (neighbours == 3 && board[i][j] == 0) {
                    nextBoard[i][j] = 1;
                }
            }
        }

        board = nextBoard;
    }
};

int main() {
    int n, m;
    cout << "Enter the number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> board(n, vector<int>(m, 0));

    cout << "Enter the initial state of the board (0 or 1):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    Solution solution;
    solution.gameOfLife(board);

    cout << "Next state of the board:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
