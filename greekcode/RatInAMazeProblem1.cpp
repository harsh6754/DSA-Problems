#include <iostream>
#include <vector>
using namespace std;

string direction = "DLRU";
int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};

bool isValid(int r, int c, int n, vector<vector<int>>& maze)
{
    return r >= 0 && c >= 0 && r < n && c < n && maze[r][c];
}

void findPath(int r, int c, vector<vector<int>>& maze, int n, vector<string>& ans, string& currentPath)
{
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(currentPath);
        return;
    }

    maze[r][c] = 0;

    for (int i = 0; i < 4; i++)
    {
        int nextr = r + dr[i];
        int nextc = c + dc[i];
        if (isValid(nextr, nextc, n, maze))
        {
            currentPath += direction[i];
            findPath(nextr, nextc, maze, n, ans, currentPath);
            currentPath.pop_back();
        }
    }
    maze[r][c] = 1;
}

int main()
{
    int n;
    cout << "Enter the size of the maze: ";
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n, 0));

    cout << "Enter the maze elements (1 for open cell, 0 for blocked cell):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }

    vector<string> result;
    string currentPath = "";

    findPath(0, 0, maze, n, result, currentPath);

    if (result.size() == 0)
        cout << -1;
    else
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
    cout << endl;

    return 0;
}
