#include <iostream>
using namespace std;

int main() {
    int numbers[] = {1, 2, 3};

    // Print the numbers in reverse order
    for (int i = 2; i >= 0; i--) {
        cout << numbers[i] << " ";
    }

    cout << endl;

    return 0;
}
