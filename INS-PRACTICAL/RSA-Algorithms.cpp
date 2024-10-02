#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

long long modExp(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent /= 2;
    }
    return result;
}

long long modInverse(long long e, long long phi) {
    long long t = 0, new_t = 1;
    long long r = phi, new_r = e;

    while (new_r != 0) {
        long long quotient = r / new_r;
        t = t - quotient * new_t;
        swap(t, new_t);
        r = r - quotient * new_r;
        swap(r, new_r);
    }

    if (r > 1) return -1;
    if (t < 0) t += phi;
    return t;
}

int main() {
    int p, q;
    
    do {
        cout << "Enter prime number p: ";
        cin >> p;
        if (!isPrime(p)) {
            cout << p << " is not a prime number. Please enter again.\n";
        }
    } while (!isPrime(p));
    
    do {
        cout << "Enter prime number q: ";
        cin >> q;
        if (!isPrime(q)) {
            cout << q << " is not a prime number. Please enter again.\n";
        }
    } while (!isPrime(q));

    long long n = p * q;
    long long phi = (p - 1) * (q - 1);

    long long e;
    do {
        cout << "Enter a value for e (1 < e < " << phi << " and gcd(e, " << phi << ") = 1): ";
        cin >> e;
    } while (gcd(e, phi) != 1);

    long long d = modInverse(e, phi);
    if (d == -1) {
        cout << "Modular inverse of e doesn't exist. Exiting.\n";
        return 0;
    }

    cout << "Public key: (" << e << ", " << n << ")\n";
    cout << "Private key: (" << d << ", " << n << ")\n";

    long long message;
    cout << "Enter a message to encrypt (an integer < " << n << "): ";
    cin >> message;

    long long encrypted = modExp(message, e, n);
    cout << "Encrypted message: " << encrypted << "\n";

    long long decrypted = modExp(encrypted, d, n);
    cout << "Decrypted message: " << decrypted << "\n";

    return 0;
}
