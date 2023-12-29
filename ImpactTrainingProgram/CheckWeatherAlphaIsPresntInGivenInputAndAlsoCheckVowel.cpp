//Take string from user
//Check Any Aplhabet is Present or not 
//if yes then check alphabet is vowel or not 
//if not print string in in valid


#include<bits/stdc++.h>
using namespace std;
int main() {
    cout << "Enter a string: ";
    string input;
    getline(cin, input);
 
    if (input.empty()) {
        cout << "The entered string is empty.\n";
        return 0;
    }

 
    cout << "Enter a character to check: ";
    char ch;
    cin >> ch;

    if (isalpha(ch)) {
        if (input.find(ch) != string npos) {
            cout << "The character '" << ch << "' is present in the string.\n";

            char lowercaseCh = tolower(ch);
            if (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u') {
                cout << "The character '" << ch << "' is a vowel.\n";
            } else {
                cout << "The character '" << ch << "' is a consonant.\n";
            }
        } else {
            cout << "The character '" << ch << "' is not present in the string.\n";
        }
    } else {
        cout << "Please enter a valid alphabet.\n";
    }

    return 0;
}
