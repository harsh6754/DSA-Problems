#include<bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

void printFirstNPrimes(int n) {
    int count = 0;
    int num = 2;

    while (count < n) {
        if (isPrime(num)) {
            cout << num << " ";
            ++count;
        }
        ++num;
    }

    cout <<endl;
}

int main() {
    int n;
    cin >> n;
    printFirstNPrimes(n);

    return 0;
}
