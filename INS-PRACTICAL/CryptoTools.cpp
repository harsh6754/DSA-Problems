#include <iostream>
#include <cmath>

using namespace std;

long long modExp(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % mod;
        exponent = exponent >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long signMessage(long long message, long long d, long long n) {
    return modExp(message, d, n);
}

long long verifySignature(long long signature, long long e, long long n) {
    return modExp(signature, e, n);
}

int main() {
    long long p, q, e;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    cout << "Enter value for e such that 1 < e < " << phi << " and gcd(e, " << phi << ") = 1: ";
    cin >> e;

    while (gcd(e, phi) != 1) {
        cout << "gcd(e, " << phi << ") is not 1. Enter a valid e: ";
        cin >> e;
    }

    long long d;
    for (d = 1; (e * d) % phi != 1; d++);

    long long message;
    cout << "Enter a message to sign (an integer): ";
    cin >> message;

    long long signature = signMessage(message, d, n);
    cout << "Digital Signature: " << signature << endl;

    long long verifiedMessage = verifySignature(signature, e, n);
    cout << "Verified Message: " << verifiedMessage << endl;

    if (verifiedMessage == message) {
        cout << "The signature is valid." << endl;
    } else {
        cout << "The signature is invalid." << endl;
    }

    return 0;
}
