#include <iostream>
using namespace std;

int main() {
    string input;
    
    // Input the string
    cout << "Enter a string: ";
    cin >> input;

    // Find the length of the string
    int length = input.length();

    // Initialize variables for checking palindrome
    int start = 0;
    int end = length - 1;
    bool isPalindrome = true;

    // Check if the string is a palindrome
    while (start < end) {
        if (input[start] != input[end]) {
            isPalindrome = false;
            break;
        }
        start++;
        end--;
    }

    // Display the result
    if (isPalindrome) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}
