#include <iostream>
#include <string>
using namespace std;

string convertToWords(int number) {
    const string units[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    const string teens[] = {"", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const string tens[] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    if (number < 0) {
        return "Negative " + convertToWords(-number);
    } else if (number >= 1000) {
        return convertToWords(number / 1000) + " thousand " + convertToWords(number % 1000);
    } else if (number >= 100) {
        return units[number / 100] + " hundred " + convertToWords(number % 100);
    } else if (number >= 20) {
        return tens[number / 10] + " " + convertToWords(number % 10);
    } else if (number >= 11) {
        return teens[number - 10];
    } else {
        return units[number];
    }
}

int main() {
    int number;
    cin>>number;
    cout << number << " in words: " << convertToWords(number) << endl;

    return 0;
}
