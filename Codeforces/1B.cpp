#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string toAlphabetic(int col) {
    string result = "";
    while (col > 0) {
        col--;  // To convert from 1-indexed to 0-indexed for easier processing
        result = char('A' + col % 26) + result;
        col /= 26;
    }
    return result;
}

int toNumber(const string &col) {
    int result = 0;
    for (char c : col) {
        result = result * 26 + (c - 'A' + 1);
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        string input;
        cin >> input;

        if (input[0] == 'R' && isdigit(input[1]) && input.find('C') != string::npos) {
            // Convert RXCY to Alphabetic format
            int row, col;
            sscanf(input.c_str(), "R%dC%d", &row, &col);
            string alphabeticCol = toAlphabetic(col);
            cout << alphabeticCol << row << endl;
        } else {
            // Convert Alphabetic format to RXCY
            int i = 0;
            while (isalpha(input[i])) i++;
            string colStr = input.substr(0, i);
            int row = stoi(input.substr(i));
            int col = toNumber(colStr);
            cout << "R" << row << "C" << col << endl;
        }
    }

    return 0;
}
