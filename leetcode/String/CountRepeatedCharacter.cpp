#include <iostream>
#include <string>

using namespace std;

string repeatedChars(const string& input) {
    int len = input.length();
    string result;
    
    for(int i = 0; i < len;) {
        char c = input[i];
        int count = 0;
        
        while(i < len && input[i] == c) {
            count++;
            i++;
        }
        
        if(count > 1) {
            result += to_string(count);
        }
        
        result += c;
    }
    
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    cout << repeatedChars(input) << endl;

    return 0;
}
