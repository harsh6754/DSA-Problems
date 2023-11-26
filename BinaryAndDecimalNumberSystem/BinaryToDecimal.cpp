#include <iostream>
#include <cmath>
using namespace std;

int binaryToDecimal(int binaryNumber) {
    int decimalNumber = 0;
    int base = 1;

    while (binaryNumber > 0) {
        int lastDigit = binaryNumber % 10;
        binaryNumber = binaryNumber / 10;

        decimalNumber += lastDigit * base;
        base *= 2;
    }

    return decimalNumber;
}

int main() {
    int binaryInput;

    // Input binary number
    cout << "Enter a binary number: ";
    cin >> binaryInput;

    // Convert binary to decimal
    int decimalOutput = binaryToDecimal(binaryInput);

    // Output the result
    cout << "Decimal equivalent: " << decimalOutput << endl;

    return 0;
}

