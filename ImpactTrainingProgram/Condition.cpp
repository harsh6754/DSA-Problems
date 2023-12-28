#include<bits/stdc++.h>
using namespace std;

int main() {
    
    int age, weight;
    
    cout << "Enter age: ";
    cin >> age;
    
    cout << "Enter weight: ";
    cin >> weight;

 
    if (age >= 12 && weight >= 40 && weight <= 110) {
        cout << "Weight is within the allowed range." << endl;
    } else if (age >= 12 && weight > 110) {
   
        cout << "Weight is greater than 110. Add extra rope." << endl;
    } else {
       
        cout << "Age or weight is not with in the allowed range." << endl;
    }

    return 0;
}
