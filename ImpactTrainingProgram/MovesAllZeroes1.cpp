#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string input;
        cin >> input;

        int count_zeros = 0;

        // Count the number of zeros and print the ones
        for (char digit : input) {
            if (digit == '0') {
                count_zeros++;
            } else {
                cout << '1';
            }
        }

        // Print the zeros at the end
        for (int i = 0; i < count_zeros; ++i) {
            cout << '0';
        }

        cout << endl;
    }

    return 0;
}
