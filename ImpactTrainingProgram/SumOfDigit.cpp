#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int number) {
    int sum = 0;

    while (number != 0) {
        sum += number % 10;
        number /= 10;       
    }

    return sum;
}

int main() {
    int num;
    cin >> num;

    int result = sumOfDigits(num);

    cout << result << endl;

    return 0;
}
