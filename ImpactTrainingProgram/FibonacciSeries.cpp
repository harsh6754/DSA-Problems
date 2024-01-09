#include <iostream>
using namespace std;

class Fibonacci {
public:
  int fib(int n) {
    if (n <= 1) {
      return n;
    } else {
      return fib(n - 1) + fib(n - 2);
    }
  }
};

int main() {
  Fibonacci fib;
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cout << fib.fib(i) << " ";
  }
  cout << endl;
  return 0;
}