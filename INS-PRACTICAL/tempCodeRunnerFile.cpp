
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