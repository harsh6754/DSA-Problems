#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int LCMofTwoNumber(int a, int b) {
    int gcdValue = gcd(a, b);
    int lcm = (a * b) / gcdValue;
    return lcm;
}

int main() {
    int a, b;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;

    cout << "LCM: " << LCMofTwoNumber(a, b) << endl;
    return 0;
}
