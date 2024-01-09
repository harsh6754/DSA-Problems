#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string name;
    string accountType;
    double balance;

public:
    void enterDetails() {
        cout << "Enter Details:" << endl;
        cout << "Account No. "<<endl;
        cin >> accountNumber;
        cout << "Name: "<<endl;
        cin.ignore();
        getline(cin, name);
        cout << "Account Type: "<<endl;
        getline(cin, accountType);
        cout << "Balance: "<<endl;
        cin >> balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
       balance -= amount;
    }

    void displayDetails() {
        cout << "Account No.: " << accountNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Account Type: " << accountType << endl;
        cout << fixed << setprecision(1);
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount recipient;

    recipient.enterDetails();

    double depositAmount, withdrawAmount;

    cout << "Enter Deposit Amount ="<<endl;
    cin >> depositAmount;
    recipient.deposit(depositAmount);

    cout << "Enter Withdraw Amount ="<<endl;
    cin >> withdrawAmount;
    recipient.withdraw(withdrawAmount);

    recipient.displayDetails();

    return 0;
}
