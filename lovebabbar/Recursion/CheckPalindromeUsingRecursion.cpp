#include <iostream>
using namespace std;
bool isPalRec(const string &str, size_t s, size_t e)
{
    if (s == e)
        return true;
    if (str[s] != str[e])
        return false;
    if (s < e + 1)
        return isPalRec(str, s + 1, e - 1);

    return true;
}

bool isPalindrome(const string &str)
{
    size_t n = str.length();
    if (n == 0)
        return true;

    return isPalRec(str, 0, n - 1);
}
int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str))
        cout << "Yes, it is a palindrome";
    else
        cout << "No, it is not a palindrome";

    return 0;
}
