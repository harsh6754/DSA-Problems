#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(vector<vector<char>> &board, int i, int j, string &word, int ind, vector<vector<bool>> &visited)
    {
        if (ind >= word.length())
        {
            return true;
        }
        int rows = board.size();
        int cols = board[0].size();
        if ((i < 0 || i >= rows || j < 0 || j >= cols) || (board[i][j] != word[ind]) || visited[i][j] == true)
        {
            return false;
        }
        visited[i][j] = true;
        bool downAns = solve(board, i + 1, j, word, ind + 1, visited);
        bool leftAns = solve(board, i, j - 1, word, ind + 1, visited);
        bool rightAns = solve(board, i, j + 1, word, ind + 1, visited);
        bool upAns = solve(board, i - 1, j, word, ind + 1, visited);
        visited[i][j] = false;
        return downAns || leftAns || rightAns || upAns;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();    // Rows Size
        int cols = board[0].size(); // Cols Size

        bool ans = false;
        int ind = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (solve(board, i, j, word, ind, visited))
                {
                    return true;
                }
            }
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    string word;
    cin >> word;

    Solution solution;

    bool result = solution.exist(board, word);
    cout << result << endl;

    return 0;
}
