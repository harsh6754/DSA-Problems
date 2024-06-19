#include<bits/stdc++.h>
using namespace std;

unordered_map<char, char> createEncryptionMap(const string& key) {
    unordered_map<char, char> encryptionMap;
    char alphabet = 'a';
    for (char c : key) {
        encryptionMap[alphabet] = c;
        alphabet++;
    }
    alphabet = 'A';
    for (char c : key) {
        encryptionMap[alphabet] = toupper(c);
        alphabet++;
    }
    return encryptionMap;
}

unordered_map<char, char> createDecryptionMap(const string& key) {
    unordered_map<char, char> decryptionMap;
    char alphabet = 'a';
    for (char c : key) {
        decryptionMap[c] = alphabet;
        alphabet++;
    }
    alphabet = 'A';
    for (char c : key) {
        decryptionMap[toupper(c)] = toupper(alphabet);
        alphabet++;
    }
    return decryptionMap;
}

string encrypt(const string& plaintext, const unordered_map<char, char>& encryptionMap) {
    string ciphertext = plaintext;
    for (char& c : ciphertext) {
        if (encryptionMap.find(c) != encryptionMap.end()) {
            c = encryptionMap.at(c);
        }
    }
    return ciphertext;
}

string decrypt(const string& ciphertext, const unordered_map<char, char>& decryptionMap) {
    string plaintext = ciphertext;
    for (char& c : plaintext) {
        if (decryptionMap.find(c) != decryptionMap.end()) {
            c = decryptionMap.at(c);
        }
    }
    return plaintext;
}

int main() {
    string key;
    cout << "Enter the key for encryption and decryption: ";
    cin >> key;
    
    unordered_map<char, char> encryptionMap = createEncryptionMap(key);
    unordered_map<char, char> decryptionMap = createDecryptionMap(key);
    
    string plaintext;
    cout << "Enter the plaintext to be encrypted: ";
    cin.ignore(); 
    getline(cin, plaintext);
    
    cout << "Plaintext: " << plaintext << endl;
    
    string ciphertext = encrypt(plaintext, encryptionMap);
    cout << "Ciphertext: " << ciphertext << endl;
    
    string decryptedtext = decrypt(ciphertext, decryptionMap);
    cout << "Decrypted text: " << decryptedtext << endl;
    
    return 0;
}
