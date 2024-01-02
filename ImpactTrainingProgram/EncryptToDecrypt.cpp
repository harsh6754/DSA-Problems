#include<bits/stdc++.h>
using namespace std;

int main() {
    string encryptedCode;
    cin >> encryptedCode;
    for (int i = 0; i < encryptedCode.length(); i += 2) {
        if (i + 1 < encryptedCode.length()) {
            
            swap(encryptedCode[i], encryptedCode[i + 1]);
        }
    }

   
    cout << encryptedCode << endl;

    return 0;
}
