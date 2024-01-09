#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 16;
    n = n|1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if ((i==0) || (i==n-1) || (j==0) || (j==n-1) || (i-j==0 && i+j==n-1) || (i==n/4) && (j<=n/4) || (j==n/4 && (i <= n/4)) || (i==n/4 && j>=3*(n/4)) || (j==3*(n/4) && i <= n/4) || (i==3*(n/4) && j <= n/4) || (j==n/4 && i >= 3*(n/4)) || (i==3*(n/4) && j >= 3*(n/4)) || (j==3*(n/4) && (i>=3*(n/4))) || (i-j==0) || (i+j==n-1)) {
                cout << "* ";
            }else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}