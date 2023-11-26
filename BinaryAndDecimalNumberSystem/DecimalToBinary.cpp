#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Input decimal number
    cout << "Enter the decimal number: ";
    cin >> n;

    if (n == 0) {
        cout << "Binary representation: 0" << endl;
        return 0;
    }

    // Temporary variables
    int binary[32]; // Assuming 32-bit integer
    int i = 0;

    // Convert decimal to binary
    while (n > 0) {
        binary[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Display binary representation
    cout << "Binary representation: ";
    for (int j = i - 1; j >= 0; j--) {
        cout << binary[j];
    }
    
    cout << endl;

    return 0;
}
