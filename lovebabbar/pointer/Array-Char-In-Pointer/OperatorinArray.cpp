#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Address of the first element using arr[0]: " << &arr[0] << endl;
    cout << "Address of the array using &arr: " << &arr << endl;
    cout << "Address of the first element using arr: " << arr << endl;

    cout << endl;

    int (*ptr)[n] = &arr; // Pointer to an array of size 'n'
    ptr = ptr + 1;

    cout << "Address of the second array (arr + 1): " << ptr << endl;
    cout << "Value at the second array: " << (*ptr)[0] << endl;

    cout << endl;

    cout << "Address of the pointer variable: " << &ptr << endl;
    cout << "Address stored in the pointer variable: " << ptr << endl;
    cout << "Value at the address stored in the pointer variable: " << (*ptr)[0] << endl;

    return 0;
}
