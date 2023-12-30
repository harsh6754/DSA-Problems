#include <iostream>

using namespace std;

string check_eligibility(int age, int year_of_passing, int family_income, int standing_arrears, float test_percentage, float attendance_percentage) {
    if (year_of_passing >= 2021 && standing_arrears <= 2 && age >= 18 && age <= 21) {
        if (family_income <= 200000) {
            if (test_percentage >= 60 && attendance_percentage >= 80) {
                return "Eligible";
            } else {
                return "Not Eligible";
            }
        } else if (family_income >= 200000 && family_income <= 250000) {
            if (test_percentage >= 60 && attendance_percentage >= 80) {
                return "Partially Eligible";
            }
        }
    } else if (standing_arrears > 2 && test_percentage >= 80 && attendance_percentage >= 90) {
        return "Eligible";
    }

    return "Not Eligible";
}

int main() {
    // Input
    int age, year_of_passing, family_income, standing_arrears;
    float test_percentage, attendance_percentage;

    cout << "Enter age: ";
    cin >> age;
    cout << "Enter year of passing: ";
    cin >> year_of_passing;
    cout << "Enter family income: ";
    cin >> family_income;
    cout << "Enter standing arrears: ";
    cin >> standing_arrears;
    cout << "Enter test percentage: ";
    cin >> test_percentage;
    cout << "Enter attendance percentage: ";
    cin >> attendance_percentage;

    // Output
    string result = check_eligibility(age, year_of_passing, family_income, standing_arrears, test_percentage, attendance_percentage);
    cout << result << endl;

    return 0;
}
