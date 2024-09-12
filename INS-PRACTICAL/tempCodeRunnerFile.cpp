#include<bits/stdc++.h>
using namespace std;

string generateRandomKey(int length) {
    string key = "";
    for (int i = 0; i < length; i++) {
        char randomChar = 'A' + rand() % 26;
        key += randomChar;
    }
    return key;
}

string encrypt(const string& plaintext, const string& key) {
    string ciphertext = "";

    for (size_t i = 0; i < plaintext.length(); i++) {
        char p = toupper(plaintext[i]);
        char k = toupper(key[i]);
        
        char c = ((p - 'A') + (k - 'A')) % 26 + 'A';
        ciphertext += c;
    }

    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key) {
    string plaintext = "";

    for (size_t i = 0; i < ciphertext.length(); i++) {
        char c = toupper(ciphertext[i]);
        char k = toupper(key[i]);

        char p = ((c - 'A') - (k - 'A') + 26) % 26 + 'A';
        plaintext += p;
    }

    return plaintext;
}

int main() {
    srand(time(0));

    string plaintext, key, ciphertext;

    cout << "Enter the plaintext (A-Z only): ";
    getline(cin, plaintext);

    cout << "Enter the key (A-Z only): ";
    getline(cin, key);

    if (plaintext.length() != key.length()) {
        cout << "Warning: Key length does not match plaintext length. Generating a random key.\n";
        key = generateRandomKey(plaintext.length());
        cout << "Generated key: " << key << endl;
    }

    ciphertext = encrypt(plaintext, key);

    cout << "Encrypted text: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
