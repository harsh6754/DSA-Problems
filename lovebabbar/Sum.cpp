 #include <iostream>
using namespace std;

int main() {
    int arr[]={1,2,3};
    int n, sum = 0;

    cout << "Enter a positive integer: ";
    cin >> n;

    for (int i = 0; i <n; i++) {
        sum += arr[i];
    }

    cout << "Sum = " << sum;
    return 0;
}