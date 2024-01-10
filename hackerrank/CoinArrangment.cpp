#include <iostream>
using namespace std;

int maxCoins(int N, int M, int X, int Y) {
    int maxCoins = 0;

    if (N == 1 || M == 1) {
        maxCoins = N * M * X;
        return maxCoins;
    }

    int diagonalSize = (X <= Y) ? X : Y;
    maxCoins = diagonalSize;

    for (int i = 2; i <= N; i++) {
        for (int j = 2; j <= M; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0)) {
                maxCoins += diagonalSize;
            } else {
                maxCoins += (X <= Y) ? X : Y;
            }
        }
    }

    return maxCoins;
}

int main() {
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;

    int result = maxCoins(N, M, X, Y);

    cout << result << endl;

    return 0;
}
