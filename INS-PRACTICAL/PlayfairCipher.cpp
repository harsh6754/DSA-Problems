#include <iostream>
#include <cstring>
using namespace std;
#define SIZE 100

int preprocessText(char str[], int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[count++] = tolower(str[i]);
        }
    }
    str[count] = '\0';
    return count;
}

void generateKeyTable(const char key[], int ks, char keyT[5][5]) {
    bool used[26] = { false };
    int i = 0, j = 0;

    for (int k = 0; k < ks; k++) {
        if (key[k] != 'j' && !used[key[k] - 'a']) {
            used[key[k] - 'a'] = true;
            keyT[i][j++] = key[k];
            if (j == 5) { i++; j = 0; }
        }
    }

    used['j' - 'a'] = true;

    for (int k = 0; k < 26; k++) {
        if (!used[k]) {
            keyT[i][j++] = 'a' + k;
            if (j == 5) { i++; j = 0; }
        }
    }
}

void search(char keyT[5][5], char a, char b, int pos[]) {
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                pos[0] = i;
                pos[1] = j;
            }
            if (keyT[i][j] == b) {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}

int prepareText(char str[], int len) {
    if (len % 2 != 0) {
        str[len++] = 'z';
        str[len] = '\0';
    }
    return len;
}

void processText(char str[], char keyT[5][5], int len, bool encrypt) {
    int pos[4];

    for (int i = 0; i < len; i += 2) {
        search(keyT, str[i], str[i + 1], pos);

        if (pos[0] == pos[2]) {
            str[i] = keyT[pos[0]][(pos[1] + (encrypt ? 1 : 4)) % 5];
            str[i + 1] = keyT[pos[0]][(pos[3] + (encrypt ? 1 : 4)) % 5];
        } else if (pos[1] == pos[3]) {
            str[i] = keyT[(pos[0] + (encrypt ? 1 : 4)) % 5][pos[1]];
            str[i + 1] = keyT[(pos[2] + (encrypt ? 1 : 4)) % 5][pos[1]];
        } else {
            str[i] = keyT[pos[0]][pos[3]];
            str[i + 1] = keyT[pos[2]][pos[1]];
        }
    }
}

void playfairCipher(char str[], const char key[], bool encrypt) {
    char keyT[5][5];
    int ks = strlen(key);
    int len = strlen(str);

    len = preprocessText(str, len);
    ks = preprocessText((char*)key, ks);

    if (encrypt) {
        len = prepareText(str, len);
    }

    generateKeyTable(key, ks, keyT);
    processText(str, keyT, len, encrypt);
}

int main() {
    char str[SIZE], key[SIZE];
    int choice;

    cout << "Enter 1 for encryption, 2 for decryption: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter key text: ";
    cin.getline(key, SIZE);

    cout << "Enter the text: ";
    cin.getline(str, SIZE);

    switch (choice) {
        case 1:
            playfairCipher(str, key, true);
            cout << "Cipher text: " << str << "\n";
            break;
        case 2:
            playfairCipher(str, key, false);
            cout << "Decrypted text: " << str << "\n";
            break;
        default:
            cout << "Invalid choice\n";
    }

    return 0;
}
