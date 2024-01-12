//Atnm Card Details 
//userName
//Password
//CardNumber
//Address
//Type-Debit/Credit
//BankName
//MobileNumber
//And Other Details
//Write A Program Build A Atm Card Details Using OOPS concept
//login
//signup
//if user not signup dont do login
// if user want data first username and password 
//passord show in hash form 
//3 time wrong password
//show forgot password and renew project 
//crud operation 
//Atm card valid or not  also give card valid date or expired date 
//forgot password - username - mobilenumber - otp - new password - confirmPassword - renew password msg 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib> // for rand and srand
#include <ctime>   // for time

using namespace std;

class AtmCard {
private:
    string userName;
    string password;
    string cardNumber;
    string address;
    string cardType;
    string bankName;
    string mobileNumber;
    bool isLoggedIn;
    double amount;  // Added member variable to store the total amount.
    int otp;        // Added member variable to store the OTP.

public:
    AtmCard() : isLoggedIn(false), amount(0.0), otp(0) {
        // Seed for random number generation
        srand(static_cast<unsigned>(time(0)));
    }

    void signUp() {
        cout << "Enter Username: ";
        cin >> userName;

        cout << "Enter Password: ";
        cin >> password; // In a real-world scenario, this password should be hashed.

        cout << "Enter Card Number: ";
        cin >> cardNumber;

        cout << "Enter Address: ";
        cin.ignore(); // Ignore the newline character in the buffer
        getline(cin, address);

        cout << "Enter Card Type (Debit/Credit): ";
        cin >> cardType;

        cout << "Enter Bank Name: ";
        cin >> bankName;

        cout << "Enter Mobile Number: ";
        cin >> mobileNumber;

        cout << "Sign-up successful!" << endl;
    }

    bool login() {
        if (!isLoggedIn) {
            string enteredUserName, enteredPassword;
            int attempts = 3;

            do {
                cout << "Enter Username: ";
                cin >> enteredUserName;

                cout << "Enter Password: ";
                cin >> enteredPassword;

                // In a real-world scenario, password comparison should involve hashing.
                if (enteredUserName == userName && enteredPassword == password) {
                    isLoggedIn = true;
                    cout << "Login successful!" << endl;
                    return true;
                } else {
                    cout << "Invalid username or password. " << --attempts << " attempts remaining." << endl;
                }
            } while (attempts > 0);

            cout << "Too many unsuccessful login attempts. Please contact customer support." << endl;
            return false;
        } else {
            cout << "User already logged in." << endl;
            return true;
        }
    }

    void addAmount(double addedAmount) {
        if (isLoggedIn) {
            amount += addedAmount;
            cout << "Amount added successfully. Total amount: " << amount << endl;
        } else {
            cout << "Please log in to perform this operation." << endl;
        }
    }

    void debitAmount(double debitedAmount) {
        if (isLoggedIn) {
            if (debitedAmount <= amount) {
                amount -= debitedAmount;
                cout << "Amount debited successfully. Remaining amount: " << amount << endl;
            } else {
                cout << "Insufficient funds." << endl;
            }
        } else {
            cout << "Please log in to perform this operation." << endl;
        }
    }

    void creditAmount(double creditedAmount) {
        if (isLoggedIn) {
            amount += creditedAmount;
            cout << "Amount credited successfully. Total amount: " << amount << endl;
        } else {
            cout << "Please log in to perform this operation." << endl;
        }
    }

    void displayTotalAmount() {
        if (isLoggedIn) {
            cout << "Total Amount: " << amount << endl;
        } else {
            cout << "Please log in to view the total amount." << endl;
        }
    }

    void displayDetails() {
        if (isLoggedIn) {
            cout << "Username: " << userName << endl;
            // Password should not be displayed here in a real-world scenario.

            cout << "Card Number: " << cardNumber << endl;
            cout << "Address: " << address << endl;
            cout << "Card Type: " << cardType << endl;
            cout << "Bank Name: " << bankName << endl;
            cout << "Mobile Number: " << mobileNumber << endl;
        } else {
            cout << "Please log in to view details." << endl;
        }
    }

    void logout() {
        if (isLoggedIn) {
            isLoggedIn = false;
            cout << "Logged out successfully." << endl;
        } else {
            cout << "No user is currently logged in." << endl;
        }
    }

    bool isCardValid() {
        // In a real-world scenario, you would compare the current date with the card's expiration date.
        // For simplicity, I am using a static expiration date one year from now.
        time_t now = time(0);
        tm* currentTime = localtime(&now);

        int currentYear = 1900 + currentTime->tm_year;
        int currentMonth = 1 + currentTime->tm_mon;

        int expirationYear, expirationMonth;
        cout << "Enter Card Expiration Year (YYYY): ";
        cin >> expirationYear;

        cout << "Enter Card Expiration Month (1-12): ";
        cin >> expirationMonth;

        if (expirationYear > currentYear || (expirationYear == currentYear && expirationMonth >= currentMonth)) {
            cout << "Card is valid until " << expirationMonth << "/" << expirationYear << "." << endl;
            return true;
        } else {
            cout << "Card has expired." << endl;
            return false;
        }
    }

    void forgotPassword() {
        if (!isLoggedIn) {
            string enteredUserName, enteredMobileNumber;

            cout << "Enter Username: ";
            cin >> enteredUserName;

            cout << "Enter Mobile Number: ";
            cin >> enteredMobileNumber;

            if (enteredUserName == userName && enteredMobileNumber == mobileNumber) {
                generateOTP();
                cout << "An OTP has been sent to your registered mobile number." << endl;

                int enteredOTP;
                cout << "Enter OTP: ";
                cin >> enteredOTP;

                if (enteredOTP == otp) {
                    string newPassword, confirmPassword;

                    cout << "Enter New Password: ";
                    cin >> newPassword;

                    cout << "Confirm New Password: ";
                    cin >> confirmPassword;

                    if (newPassword == confirmPassword) {
                        password = newPassword;
                        cout << "Password reset successful. Please log in with your new password." << endl;
                    } else {
                        cout << "Password confirmation does not match. Password reset failed." << endl;
                    }
                } else {
                    cout << "Incorrect OTP. Password reset failed." << endl;
                }
            } else {
                cout << "Invalid username or mobile number. Password reset failed." << endl;
            }
        } else {
            cout << "Please log out before attempting to reset the password." << endl;
        }
    }

private:
    void generateOTP() {
        otp = rand() % 9000 + 1000; // Generate a 4-digit random OTP
    }
};

int main() {
    AtmCard atmCard;

    int choice;

    do {
        cout << "\n1. Sign Up\n2. Login\n3. Display Card Details\n"
             << "4. Check Card Validity\n5. Logout\n6. Add Amount\n"
             << "7. Debit Amount\n8. Credit Amount\n9. Display Total Amount\n"
             << "10. Forgot Password\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                atmCard.signUp();
                break;

            case 2:
                if (atmCard.login()) {
                    // Additional operations after successful login can be added here.
                }
                break;

            case 3:
                atmCard.displayDetails();
                break;

            case 4:
                atmCard.isCardValid();
                break;

            case 5:
                atmCard.logout();
                break;

            case 6:
                double addAmount;
                cout << "Enter the amount to add: ";
                cin >> addAmount;
                atmCard.addAmount(addAmount);
                break;

            case 7:
                double debitAmount;
                cout << "Enter the amount to debit: ";
                cin >> debitAmount;
                atmCard.debitAmount(debitAmount);
                break;

            case 8:
                double creditAmount;
                cout << "Enter the amount to credit: ";
                cin >> creditAmount;
                atmCard.creditAmount(creditAmount);
                break;

            case 9:
                atmCard.displayTotalAmount();
                break;

            case 10:
                atmCard.forgotPassword();
                break;

            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
