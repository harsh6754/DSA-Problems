#include<bits/stdc++.h>
using namespace std;

char toLowerCase(char ch) {
    if(ch >= 'a' && ch <= 'z') {
        return ch;
    } else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool isPalindrome(char ch[], int n) {
    int s = 0;
    int e = n - 1;
    while(s < e) {
        if(!isalnum(ch[s])) {
            s++;
            continue;
        }
        if(!isalnum(ch[e])) {
            e--;
            continue;
        }
        if(toLowerCase(ch[s]) != toLowerCase(ch[e])) {
            return false;
        } else {
            s++;
            e--;
        }
    }
    return true;
}

void reverse(char ch[], int n) {
    int s = 0;
    int e = n - 1;
    while(s < e) {
        swap(ch[s], ch[e]);
        s++;
        e--;
    }
}

int getLength(char ch[]) {
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int main() {
    char ch[100];
    cout << "Enter Your Name: ";
    cin >> ch;

    cout << "Your Name is: " << ch << endl;

    int len = getLength(ch);
    cout << "Length Of String: " << len << endl;

   
    for (int i = 0; i < len; ++i) {
        if (!isalnum(ch[i])) {
            for (int j = i; j < len - 1; ++j) {
                ch[j] = ch[j + 1];
            }
            ch[len - 1] = '\0';
            --len;
            --i;  
        }
    }

    cout << "String after removing special symbols: " << ch << endl;

    reverse(ch, len);
    cout << "Reverse Name is: " << ch << endl;

    cout << "String is Palindrome? : " << (isPalindrome(ch, len) ? "Yes" : "No") << endl;

    return 0;
}
