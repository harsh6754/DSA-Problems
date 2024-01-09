#include<iostream>
using namespace std;

class ElectricityBill {
private:
    int billNumber;
    string name;
    int units;

public:
    void input() {
        cin >> billNumber;
        cin.ignore(); // Ignore newline character
        getline(cin, name);
        cin >> units;
    }

    int calculateBill() {
        int cost = 0;

        if (units <= 100) {
            cost = units * 1.20;
        } else if (units <= 300) {
            cost = 100 * 1.20 + (units - 100) * 2;
        } else {
            cost = 100 * 1.20 + 200 * 2 + (units - 300) * 3;
        }

        return cost;
    }

    void output() {
        cout << billNumber << endl;
        cout << name << endl;
        cout << units << endl;
        cout << calculateBill() << endl;
    }
};

int main() {
    ElectricityBill bill;

    bill.input();
    bill.output();

    return 0;
}
