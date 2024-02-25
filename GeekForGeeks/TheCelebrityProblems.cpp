#include <iostream>
#include <vector>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (M[c][i] == 1)
            c = i;
    }
    for (int i = 0; i < n; i++) {
        if (i != c && (M[c][i] == 1 || M[i][c] == 0))
            return -1;
    }
    return c;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<vector<int> > M(n, vector<int>(n, 0));
    cout << "Enter the matrix indicating who knows whom (1 for knowing, 0 for not knowing):\n";
    for (int i = 0; i < n; i++) {
        cout << "Enter row " << (i + 1) << ": ";
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    int celeb = celebrity(M, n);
    if (celeb == -1)
        cout << "No celebrity found.\n";
    else
        cout << "The celebrity is person " << (celeb + 1) << ".\n";

    return 0;
}
