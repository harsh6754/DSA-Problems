#include <bits/stdc++.h>
using namespace std;
void Encrypt(string inputText, int shift) {
    for(char &s: inputText) {
        if(isalpha(s)) {
            if(s<'a') {
                s+=shift;          
                if(s>'Z') s-=26;   
            } else {
                s+=shift;       
                if(s>'z') s-=26;
            }
        } 
    }

    cout << "The encoded message is " << inputText << "\n";
}
void Decrypt(string inputText, int shift) {
    for(char &s: inputText) {
        if(isalpha(s)) {
            if(s<'a') {
                s-=shift; 
                if(s<'A') s+=26; 
            } else {
                s-=shift; 
                if(s<'a') s+=26;
            }
        }
    }

    cout << "The decoded message is " << inputText << "\n";
}

int main() {
    
    string codeType, inputText;
    int shift;

    cout << "Type 'encode' to encrypt or 'decode' to decrypt: ";
    cin >> codeType;
    
    if(codeType != "encode" && codeType != "decode") {
        cout << "Invalid input\n";
        return 0;
    }

    cout << "Type the message: ";
    cin >> inputText;

    cout << "Enter the number of shifts: ";
    cin >> shift;

    if(codeType == "encode") Encrypt(inputText,shift);
    else Decrypt(inputText,shift);

    return 0;
}