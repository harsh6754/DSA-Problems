//month [3]
//per day Room Charge[1500]
//Days stay[2]
//[1,3,2,7,8,9,10] 1500*Days
//[4,5,6,11,12] 1500+20%*Days


#include<bits/stdc++.h>
using namespace std;

int calculateRoomCharge(int daysStayed, const std ::vector<int>& daysList, int month, int perDayRoomCharge,  int PercentInAnotherMonth) {
    int roomCharge = 0;

    for (int day : daysList) {
        if (day <= month) {
            roomCharge += perDayRoomCharge * daysStayed;
        } else {
            roomCharge += static_cast<int>(perDayRoomCharge + (PercentInAnotherMonth / 100.0) * perDayRoomCharge) * daysStayed;
        }
    }

    return roomCharge;
}

int main() {
    // Assuming month is March (month number 3)
    int month;
    cin >> month;
    int perDayRoomCharge;
    cout << "Enter the amount per day: ";
    cin >> perDayRoomCharge;

    // Assuming days stayed is 2
    int daysStayed;
    cout << "Enter days Stayed in Hotel: ";
    cin >> daysStayed;

    float PercentInAnotherMonth;
    cout << "Enter Percent in Another Month: ";
    cin >> PercentInAnotherMonth;

    // List of days
    vector<int> daysList = {1, 3, 2, 7, 8, 9, 10, 4, 5, 6, 11, 12};

    // Calculate room charge
    int totalRoomCharge = calculateRoomCharge(daysStayed, daysList, month, perDayRoomCharge, PercentInAnotherMonth);

    // Display the result
    cout << "Total Room Charge for month " << month << ": " << totalRoomCharge << endl;

    return 0;
}
