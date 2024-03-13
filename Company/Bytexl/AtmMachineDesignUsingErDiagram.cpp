#include <iostream>
using namespace std;

class BankCustomer {
private:
  string customerName;
  string address;
  string email;
  ATMCard* card;

public:
  BankCustomer(const string& customerName, const string& address, const string& email, ATMCard* card) :
    customerName(customerName), address(address), email(email), card(card) {}

  // Getters and Setters omitted for brevity
};

class ATMCard {
private:
  int PIN;
  long cardID;
  Account* acc;

public:
  ATMCard(int PIN, long cardID, Account* acc) : PIN(PIN), cardID(cardID), acc(acc) {}

  bool insertCard() {
    // Simulates inserting a card - replace with actual logic
    return true;
  }

  void setPIN(int newPIN) {
    PIN = newPIN;
  }

  int getPIN() const {
    return PIN;
  }

  Account* getAccount() {
    return acc;
  }
};

class Account {
private:
  int accountNumber;
  double balance;

public:
  Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

  double getBalance() const {
    return balance;
  }

  void updateBalance(double amount) {
    balance += amount;
  }
};

int main() {
  string name, address, email;
  int pin, accountNumber;
  double initialBalance;

  // Get customer information
  cout << "Enter your name: ";
  getline(cin, name);
  cout << "Enter your address: ";
  getline(cin, address);
  cout << "Enter your email: ";
  getline(cin, email);

  // Get ATM card information (assuming card ID is pre-assigned)
  cout << "Enter your card PIN: ";
  cin >> pin;
  cout << "Enter your account number: ";
  cin >> accountNumber;
  cout << "Enter your initial balance: ";
  cin >> initialBalance;

  // Create BankCustomer, ATMCard, and Account objects
  BankCustomer customer(name, address, email, nullptr);
  ATMCard card(pin, 1234567890123456, new Account(accountNumber, initialBalance));
  customer.setCard(&card);

  int choice;

  do {
    cout << "\nATM Menu:\n";
    cout << "1. Check Balance\n";
    // Add other menu options here (e.g., Withdraw, Deposit, etc.)
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Your current balance is: $" << card.getAccount()->getBalance() << endl;
        break;
      // Add other cases for menu options here
      case 0:
        cout << "Exiting ATM..." << endl;
        break;
      default:
        cout << "Invalid choice. Please try again." << endl;
    }
  } while (choice != 0);

  return 0;
}
