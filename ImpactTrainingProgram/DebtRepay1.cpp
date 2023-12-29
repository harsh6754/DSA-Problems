#include<bits/stdc++.h>
using namespace std;

int main() {
    // Input
    float principal, rate, years;
    cin >> principal >> rate >> years;

    // Calculate interest
    float interest = (principal * rate * years) / 100.0;

    // Calculate amount
    float amount = principal + interest;

    // Calculate discount
    float discount = 0.02 * interest;

    // Calculate final settlement
    float final_settlement = amount - discount;

    // Output with two decimal places
    cout << fixed << setprecision(2);
    cout << interest << endl;
    cout << amount << endl;
    cout << discount << endl;
    cout << final_settlement << endl;

    return 0;
}
