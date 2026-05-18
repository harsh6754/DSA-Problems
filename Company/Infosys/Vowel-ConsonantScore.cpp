#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);
    
    int vowelScore = 0, consonantScore = 0;
    
    for (char c : text) {
        c = tolower(c);
        
        if (isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowelScore++;
            } else {
                consonantScore++;
            }
        }
    }
    
    cout << "Vowel Score: " << vowelScore << endl;
    cout << "Consonant Score: " << consonantScore << endl;
    
    return 0;
}