#include <iostream>
using namespace std;

int main() {
    int n, value = 0, sum = 0;

    cout << "Enter the number for which you want to know the table: ";
    cin >> n;

    for (int i = 1; i <= 10; ++i) {
        value = n * i;
        cout << value << " ";
        sum += value;
    }

    cout << "\nSum is " << sum << endl;

    return 0;
}
