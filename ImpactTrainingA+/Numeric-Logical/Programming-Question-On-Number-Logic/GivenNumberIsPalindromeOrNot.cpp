#include<iostream>
using namespace std;

// Function to check if a number is palindrome
bool isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;
    
    while(num != 0) {
        int rem = num % 10;
        num /= 10;
        reversedNum = reversedNum * 10 + rem;
    }

    return (originalNum == reversedNum);
}

int main() {
    int num;
    cin >> num;

    if (isPalindrome(num))
        cout << num <<" It is Palindrome";
    else
        cout << num << " It is not Palindrome";

    return 0;
}
