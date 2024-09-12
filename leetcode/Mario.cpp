#include <iostream>
#include <vector>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<char>> mat(row, vector<char>(col, '0'));
    for (int i = 0; i < row; i++) {
        char s[100];
        cin >> s;
        for (int j = 0; j < col; j++) {
            mat[i][j] = s[j];
        }
    }

    int res = 0;
    for (int i = 0; i < col; i++) {
        int temp = row;
        for (int j = 0; j < row; j++) {
            if (mat[j][i] == 'C') {
                temp = row - j - 1;
                break;
            }
 else if (mat[j][i] == 'H') {
                if (temp != 0) 
                   continue;
                else 
                   temp = row - j;
            }
 else if (mat[j][i] == '0') {
                temp = 0;
            }
        }
        res = res+temp;
    }

    int coin = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (mat[i][j] == 'C')
               coin++;
        }
    }
    cout << coin << " " << res * 2;
    return 0;
}