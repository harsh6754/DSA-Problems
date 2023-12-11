#include <iostream>
#include <stdlib.h>
using namespace std;
 
// FUNCTION PROTOTYPES:                          // LIST/DESCRIPTION OF THE FUNCTIONS:
int atmMainMenu(int&, string&, string&);         // 1. Displays the ATM main menu.
int mainMenuVal(int&, string&, string&);         // 2. Validates the user's input from the ATM main menu.
int createAccount(string&, string&);             // 3. Creates the user an account with user name & password.
int loginMenu(int&, string&, string&);           // 4. Displays the login menu & validates the user's account info.
int userPickVal(int&, string&, string&);         // 5. Main menu input validation, switch function, & function calls.
int accessMenu(int&, float&, float&, float&);    // 6. Displays the account action menu after account login success.
int accessMenuVal(int&, float&, float&, float&); // 7. Validates the user's input in the account menu selection.
float deposit(float&, float&, float&);           // 8. Requests & calculates the deposit amount in the user's account.
float withdraw(float&, float&, float&);          // 9. Requests & calculates the withdraw amount in the user's account.
 
// MAIN FUNCTION
int main()
{
    // Initialized variables.
    int userPick = 0;
    string username;
    string password;
 
    // Function call: Displays the main menu selections.
    atmMainMenu(userPick, username, password);
 
}
 
// 1. Displays the ATM main menu.
int atmMainMenu(int &userPick, string &username, string &password)
{
        cout << "-------------------------------------------\n";
        cout << "       R&B Community Bank ATM machine\n";
        cout << "-------------------------------------------\n" << endl;
        cout << "Please select an option from the menu below: \n";
        cout << "1. Login\n";
        cout << "2. Create a New Account\n";
        cout << "3. Quit\n" << endl;
        cout << "Please select your choice: ";
        cin >> userPick;
 
        // Function calls: Validates user's input.
        mainMenuVal(userPick, username, password);
        userPickVal(userPick, username, password);
 
            return userPick;
}
 
// 2. Validates the user's input from the ATM main menu.
int mainMenuVal(int &userPick, string &username, string &password)
{
    // Displays an error if userPick is not 1, 2, or 3.
    // Directs the user back to the main menu.
    while (userPick < 1 || userPick > 3)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2, or 3.\n" << endl;
        userPick = atmMainMenu(userPick, username, password);
    }
    return 0;
}
 
// 3. Creates the user an account with user name & password.
int createAccount(string &username, string &password)
{
 
        cout << "-------------------------------------------\n";
        cout << "             Create an Account\n";
        cout << "-------------------------------------------\n" << endl;
        cout << "Enter the user name of your choice: ";
        cin >> username;
        cout << "Enter a password of your choice: ";
        cin >> password;
        cout << "\nINFO: Your account has been created successfully!\n";
        cout <<endl;
 
    return 0;
 
}
 
// 4. Displays the login menu & validates the user's account info.
int loginMenu(int &userPick, string &username, string &password)
{
        // Initialized variables.
        string username2;
        string password2;
        float balance = 0.00;
        float withdrawDeposit = 0.00;
        float number = 0.00;
 
        // Displays the menu.
        cout << "-------------------------------------------\n";
        cout << "             Log into your Account\n";
        cout << "-------------------------------------------\n" << endl;
        cout << "Enter your user name: ";
        cin >> username2;
 
            // If user name matches, a password will be prompted.
            if (username2 == username)
            {
                cout << "\nEnter your Password: ";
                cin >> password2;
 
                    // If password matches, displays the account action menu.
                    if (password2 == password)
                        {
                            cout << "\nLogin Successful!" << endl;
                            int userChoice = 0;
                            accessMenu(userChoice, balance, withdrawDeposit, number);
                        }
 
                    // If password does not match, then displays an error message.
                    // The user will be directed back to the main menu.
                    else if (password2!= password)
                        {
                            cout << "\n";
                            cout << "ERROR: Incorrect Password!\n";
                            cout << "\n";
                            atmMainMenu(userPick, username, password);
                        }
 
                    // TEST ERROR MESSAGE.
                    else
                        {
                            cout << "INTERNAL ERROR!";
                        }
            }
 
            // If user name does not match, then displays an error message.
            // User will be directed back to the main menu.
            else if (username2 != username)
                {
                    cout << "\n";
                    cout << "ERROR: Incorrect User name!\n";
                    cout << "\n";
                    atmMainMenu(userPick, username, password);
                }
            // TEST ERROR MESSAGE.
            else
                {
                    cout << "internal error 2";
                }
 
        return 0;
}
 
// 5. Main menu input validation, switch function, & function calls.
int userPickVal(int &userPick, string &username, string &password)
{
    // Validates the user's input & executes function calls.
    switch (userPick)
    {
        // Case 1 - Displays the login menu.
        case 1:
            loginMenu(userPick, username, password);
            break;
 
        // Case 2 - Creates a user name & password.
        case 2:
            createAccount(username, password);
            atmMainMenu(userPick, username, password);
            break;
 
        // Case 3 - The program exits.
        case 3:
            cout << "\nThank you for using our ATM Machine!\n";
            exit(0);
            break;
 
        // TEST ERROR MESSAGE.
        default:
            cout << "INTERNAL ERROR" << endl;
    }
    return 0;
}
 
// 6. Displays the account action menu after account login success.
int accessMenu(int &userChoice, float &balance, float &withdrawDeposit, float &number)
{
 
        cout << "-------------------------------------------\n";
        cout << "                 Action Menu\n";
        cout << "-------------------------------------------\n" << endl;
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Request Balance\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        accessMenuVal(userChoice, balance, withdrawDeposit, number);
 
            // Validates the user's input & executes function calls.
            switch(userChoice)
            {
                // Case 1 - Requests a deposit amount from the user.
                case 1:
                    balance = deposit(balance, withdrawDeposit, number);
                    accessMenu(userChoice, balance, withdrawDeposit, number);
                    break;
 
                // Case 2 - Requests a withdraw amount from the user.
                case 2:
                    balance = withdraw(balance, withdrawDeposit, number);
                    accessMenu(userChoice, balance, withdrawDeposit, number);
                    break;
 
                // Case 3 - Displays the user's current balance.
                case 3:
                    cout << "\nYour balance for your account is: $" << balance;
                    cout << endl;
                    accessMenu(userChoice, balance, withdrawDeposit, number);
                    break;
 
                 // Case 4 - The program exits.
                case 4:
                    userChoice = 0;
                    cout << "\nThank you for using our ATM Machine!";
                    cout << endl;
                    exit(0);
                    break;
 
                // TEST ERROR MESSAGE.
                default:
                    cout << "ERROR: Please enter a valid option from the menu!";
 
            }
 
        return 0;
 
}
 
// 7. Validates the user's input in the account menu selection.
int accessMenuVal(int &userChoice, float &balance, float &withdrawDeposit, float &number)
{
    // If true, program displays an error message.
    while (userChoice < 1 || userChoice > 4)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2, 3 , or 4.\n" << endl;
        accessMenu(userChoice, balance, withdrawDeposit, number);
    }
    return 0;
}
 
// 8. Requests & calculates the deposit amount in the user's account.
float deposit(float &balance, float &withdrawDeposit, float &number)
{
    cout << "Enter the amount of money to deposit: $";
    cin >> withdrawDeposit;
    cout << "\nDeposit successful! ";
    cout << endl;
    balance += withdrawDeposit;
 
        // Returns the total balance after a deposit.
        return balance;
}
 
// 9. Requests & calculates the withdraw amount in the user's account.
float withdraw(float &balance, float &withdrawDeposit, float &number)
{
    // Requests the withdraw amount.
    cout << "Enter the amount of money to withdraw: $";
    cin >> number;
    balance -= number;
 
        // Validates whether the user has enough funds to execute a withdraw.
        while (balance < 0.00)
        {
            // Displays an error if balance is a negative value.
            // Also sends the user back to the action menu.
            int userChoice = 0;
            cout << "\n          **ERROR** - Withdraw amount.\n";
            cout << "You do not have enough funds to withdraw that amount.\n";
            cout << endl;
            cout << "Choose from the menu again.\n";
            cout << endl;
            balance += number;
            accessMenu(userChoice, balance, withdrawDeposit, number);
        }
 
    // Returns the balance value if balance is not a negative value.
    cout << "\nWithdraw successful! ";
    cout << endl;
        return balance;
}
