#include <iostream>
using namespace std;

bool isVowel(char ch) {
    ch = toupper(ch);
    
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

int countVowels(string str, int n) {
    if (n == 0) 
        return isVowel(str[0]);
    
    return countVowels(str, n - 1) + isVowel(str[n]);
}

int main() 
{
  
    string str;
    cin >> str;
    
    int len = str.length();
    
    cout << "Number of vowels"<< ": ";
    cout << countVowels(str, len - 1);
    
    return 0;
}
