#include <iostream>

using namespace std;

int main() {
    int inches;

    cout << "Enter the value of inches: ";
    cin >> inches;

    if (inches <= 0) {
        cout << "Invalid input. Inches must be a positive integer." << endl;
        return 1;
    }

    int centimeters = inches * 2.54;
    cout << "Centimeters: " << centimeters << endl;

    return 0;
}