
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int i, x;
    cin >> i >> x;

    int count = 0;

    for (int a = 1; a <= i; a++) {
        for (int b = 1; b <= i; b++) {
            if (gcd(a, b) == x) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
