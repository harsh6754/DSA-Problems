#include<bits/stdc++.h>
using namespace std;

int main() {

    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    int fixedCost = 100;

    int profit = (a * (b - c)) - fixedCost;

 
    cout <<profit << endl;

    return 0;
}
