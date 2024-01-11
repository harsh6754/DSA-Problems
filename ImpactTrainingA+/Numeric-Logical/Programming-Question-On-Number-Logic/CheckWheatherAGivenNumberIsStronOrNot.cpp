#include<bits/stdc++.h>
using namespace std;

// Function prototypes
int factorial(int n);
bool isPrime(int num);
int sumOfDigits(int num);

int main() {
  int num, sum = 0;

  cout << "Enter a number: ";
  cin >> num;

  int originalNum = num;  // Save the original input

  while (num > 0) {
    sum += factorial(num % 10);
    num /= 10;
  }

  if (sum == originalNum) {
    cout << originalNum << " is a strong number." << endl;
  } else {
    cout << originalNum << " is not a strong number." << endl;
  }

  return 0;
}

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  }

  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return false;
    }
  }

  return true;
}

int sumOfDigits(int num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}
