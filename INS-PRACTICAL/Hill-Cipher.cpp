#include <iostream>
#include <string>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
    int x, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;
            for (x = 0; x < 3; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}

void HillCipher(string message, string key) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);
    int messageVector[3][1];
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (message[i]) % 65;
    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);
    string CipherText;
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 65;
    cout << "Ciphertext: " << CipherText << endl;
}

int main() {
    string message;
    string key;
    int choice;

    cout << "Enter the message (3 characters): ";
    cin >> message;

    cout << "Enter the key (9 characters): ";
    cin >> key;

    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;

    switch (choice) {
        case 1:
            HillCipher(message, key);
            break;
        case 2:
            cout << "Decryption functionality is not implemented in this example." << endl;
            break;
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
