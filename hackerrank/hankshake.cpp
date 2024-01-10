#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        int handshakes = N * (N - 1) / 2;

        cout << handshakes << endl;
    }

    return 0;
}
