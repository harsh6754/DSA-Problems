#include <iostream>
using namespace std;

string convertPlaneTextToCipherText(string planText, string key) {
    int textsize = planText.size();
    int keysize = key.size();

    int i = 0, j = 0;

    string ans = "";

    while (j < textsize) {
        ans += ('a' + (((planText[j] - 'a') + (key[i] - 'a')) % 26));
        i++;
        j++;

        if (i == keysize) {
            i = 0;
        }
    }

    return ans;
}

string convertCipherTextToPlaneText(string cipherText, string key) {
    int textsize = cipherText.size();
    int keysize = key.size();

    int i = 0, j = 0;

    string ans = "";

    while (j < textsize) {
        ans += ('a' + (((cipherText[j] - 'a') - (key[i] - 'a') + 26) % 26));
        i++;
        j++;

        if (i == keysize) {
            i = 0;
        }
    }

    return ans;
}

int main() {
    string planText;
    string key;
    int choice;

    cout << "Enter 1 for Encryption or 2 for Decryption: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter plain text: ";
        getline(cin, planText);
        cout << "Enter key: ";
        getline(cin, key);

        string cipherText = convertPlaneTextToCipherText(planText, key);

        cout << "Cipher Text: " << cipherText << endl;
    } else if (choice == 2) {
        cout << "Enter cipher text: ";
        getline(cin, planText);
        cout << "Enter key: ";
        getline(cin, key);

        string plainText = convertCipherTextToPlaneText(planText, key);

        cout << "Plain Text: " << plainText << endl;
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
