#include <iostream>
using namespace std;

int main() {
    int n ;
    cin>>n;

    int a = 1, b = 1;
    for (int i = 0; i < n;++i) {
        for (int j = 0; j <= i; ++j) {
            cout << a << " ";
            int next = a + b;
            a = b;
            b = next;
        }

        cout << endl; 
    }

    return 0;
}
