#include<bits/stdc++.h>
using namespace std;

int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

double calculateResult(int n, int x) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return pow(x, n) / fact;
}

int main() {
    int n, x;
    cin >> n >> x;

    double result = calculateResult(n, x);

    cout  << result << endl;

    return 0;
}
