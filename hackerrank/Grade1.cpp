#include<bits/stdc++.h>
using namespace std;

int main() {
    string Name;
    int Age;
    char Gender;
    int TotalMarks;

    cout << "Name:";
    getline(cin, Name);  // Allowing spaces in the name

    cout << "Age:";
    cin >> Age;

    cout << "Gender:";
    cin >> Gender;

    cout << "Total Marks:";
    cin >> TotalMarks;

    float Percentage = (static_cast<float>(TotalMarks) / 500) * 100;
    char Grade;

    if (Percentage > 90)
        Grade = 'A';
    else if (Percentage > 80)
        Grade = 'B';
    else if (Percentage > 70)
        Grade = 'C';
    else if (Percentage > 60)
        Grade = 'D';
    else
        Grade = 'F';

    // Outputting the student details
    cout << "Name:" << Name << endl;
    cout << "Age:" << Age << endl;
    cout << "Gender:" << Gender << endl;
    cout << "TotalMarks:" << TotalMarks << endl;
    cout << "Percentage:" << fixed << setprecision(1) << Percentage << endl;
    cout << "Grade:" << Grade << endl;

    return 0;
}
