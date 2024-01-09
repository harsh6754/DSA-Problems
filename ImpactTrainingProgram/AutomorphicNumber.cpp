#include <iostream>
using namespace std;

class Automorphic {
public:
  virtual bool isAutomorphic(int n) = 0;
};

class AutomorphicNumber : public Automorphic {
public:
  bool isAutomorphic(int n) {
    int sq = n * n;
    while (n > 0) {
      if (n % 10 != sq % 10) {
        return false;
      }
      n /= 10;
      sq /= 10;
    }
    return true;
  }
};

int main() {
  AutomorphicNumber automorphicNumber;
  int n;
  cout << "Enter a number: ";
  cin >> n;
  if (automorphicNumber.isAutomorphic(n)) {
    cout << n << " is an automorphic number." << endl;
  } else {
    cout << n << " is not an automorphic number." << endl;
  }
  return 0;
}