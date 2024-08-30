#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);
        backtrack(solutions, board, cols, diag1, diag2, 0, n);
        return solutions;
    }

private:
    void backtrack(vector<vector<string>>& solutions, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int row, int n) {
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) continue;
            
            board[row][col] = 'Q';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
            backtrack(solutions, board, cols, diag1, diag2, row + 1, n);
            board[row][col] = '.';
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
        }
    }
};

int main() {
    int n;
    
    // Input the size of the chessboard
    cout << "Enter the value of n (size of the chessboard): ";
    cin >> n;

    // Create an instance of the Solution class and solve the problem
    Solution solution;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    // Output the solutions
    cout << "Total number of solutions: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
