#include <bits/stdc++.h>
using namespace std;

string Encryption(int no_rows, int len_key, int len_msg, string msg, int col_val[]) {
    int x = 0;
    char enc_mat[no_rows + 1][len_key];

    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            if (x >= len_msg) {
                enc_mat[i][j] = '_';
            } else {
                enc_mat[i][j] = msg[x];
            }
            x++;
        }
    }

    int t = 1;
    string cipher = "";

    while (t <= len_key) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    cipher += enc_mat[j][i];
                }
                t++;
            }
        }
    }
    return cipher;
}

string Decryption(int no_rows, int len_key, string cipher, int col_val[]) {
    char dec_mat[no_rows + 1][len_key];
    int x = 0, t = 1;

    while (t <= len_key) {
        for (int i = 0; i < len_key; i++) {
            int k = col_val[i];
            if (k == t) {
                for (int j = 0; j < no_rows + 1; j++) {
                    dec_mat[j][i] = cipher[x];
                    x++;
                }
                t++;
            }
        }
    }

    string message = "";
    for (int i = 0; i < no_rows + 1; i++) {
        for (int j = 0; j < len_key; j++) {
            if (dec_mat[i][j] == '_') {
                dec_mat[i][j] = ' ';
            }
            message += dec_mat[i][j];
        }
    }
    return message;
}

int main() {
    string msg, key;
    int choice;

    cout << "Enter the message: ";
    getline(cin, msg);
    cout << "Enter the key: ";
    cin >> key;

    int len_key = key.length();
    int len_msg = msg.length();

    int val = 1, count = 0, ind;

    int col_val[len_key];
    memset(col_val, 0, sizeof(col_val));

    while (count < len_key) {
        int min = 999;
        for (int i = 0; i < len_key; i++) {
            if ((min > int(key[i])) && (col_val[i] == 0)) {
                min = int(key[i]);
                ind = i;
            }
        }
        col_val[ind] = val;
        count++;
        val++;
    }

    int no_rows = len_msg / len_key;

    cout << "Choose operation:\n1. Encrypt\n2. Decrypt\n";
    cin >> choice;
    cin.ignore();  // To clear the newline character from the input buffer

    switch (choice) {
        case 1: {
            string cipher_text = Encryption(no_rows, len_key, len_msg, msg, col_val);
            cout << "Encrypted Message: " << cipher_text << endl;
            break;
        }
        case 2: {
            string cipher_text;
            cout << "Enter the cipher text: ";
            getline(cin, cipher_text);
            string original_msg = Decryption(no_rows, len_key, cipher_text, col_val);
            cout << "Decrypted Message: " << original_msg << endl;
            break;
        }
        default:
            cout << "Invalid choice." << endl;
    }

    return 0;
}
