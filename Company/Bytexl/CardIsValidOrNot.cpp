#include <iostream>
#include <unordered_set>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main() {
    using namespace std;

    long long int num;
    unordered_set<int> digitSet;

    cout << "Enter a 16-digit number (not starting with 0): ";
    cin >> num;

    if (num < 1000000000000000 || num >= 10000000000000000) {
        cout << "Invalid input. Please enter a 16-digit number." << endl;
        return 0;
    }

    string numStr = to_string(num);

    // Check uniqueness of digits
    for (char digit : numStr) {
        int d = digit - '0';
        if (digitSet.count(d) == 1) {
            cout << "Digits are not unique. Please enter a number with unique digits." << endl;
            return 0;
        }
        digitSet.insert(d);
    }

    int sumEven = 0, sumOddMultTwo = 0;
    for (int i = 0; i < 16; i++) {
        int digit = numStr[i] - '0';

        if (i % 2 == 0) {
            sumEven += digit;
        } else {
            sumOddMultTwo += digit * 2;
        }
    }

    int sumTotal = sumEven + sumOddMultTwo;
    if (factorial(10) == sumTotal) {
        cout << "Valid" << endl;
    } else {
        cout << "Invalid" << endl;
    }

    return 0;
}
