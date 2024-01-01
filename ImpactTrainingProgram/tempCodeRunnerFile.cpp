#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cin >> n;

    int result = fibonacci(n);

    cout << "The term " << n << " in the Fibonacci series is " << result << endl;

    return 0;
}
