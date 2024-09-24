#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

bool isPrimitiveRoot(int x, int q) {
    set<int> powers;
    for (int i = 1; i < q; ++i) {
        int power = static_cast<int>(pow(x, i)) % q;
        if (powers.find(power) != powers.end()) return false;
        powers.insert(power);
    }
    return powers.size() == q - 1;
}

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int q, x, xa, xb;

    cout << "Enter value for q: ";
    cin >> q;

    do {
        cout << "Enter value for x (primitive root of q): ";
        cin >> x;
    } while (!isPrimitiveRoot(x, q));

    cout << "Enter private key for Alice (xa): ";
    cin >> xa;

    cout << "Enter private key for Bob (xb): ";
    cin >> xb;

    int ya = modExp(x, xa, q);
    int yb = modExp(x, xb, q);

    int ka = modExp(yb, xa, q);
    int kb = modExp(ya, xb, q);

    cout << "Key A: " << ka << endl;
    cout << "Key B: " << kb << endl;

    return 0;
}
