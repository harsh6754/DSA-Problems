#include <iostream>
using namespace std;

int main() {
    int size, position, element;
    cin >> size;
    int array[size];
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }
    cin >> position >> element;
    if (position < 1 || position > size + 1) {
        cout << "Invalid Input" << endl;
        return 0;
    }
    for (int i = size; i >= position; --i) {
        array[i] = array[i - 1];
    }
    array[position - 1] = element;
    cout << "Array after insertion is" << endl;
    for (int i = 0; i < size + 1; ++i) {
        cout << array[i] << endl;
    }

    return 0;
}
