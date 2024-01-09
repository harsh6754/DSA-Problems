#include<bits/stdc++.h>
using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;

    // Constructor to initialize the time object
    Time(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    // Function to add two time objects
    Time addTime(const Time& t) const {
        Time result(0, 0, 0);
        result.seconds = seconds + t.seconds;
        result.minutes = minutes + t.minutes + result.seconds / 60;
        result.hours = hours + t.hours + result.minutes / 60;

        result.seconds %= 60;
        result.minutes %= 60;

        return result;
    }
};

int main() {
    // Input for the first time
    int hour1, minute1, second1;
    cin >> hour1 >> minute1 >> second1;

    // Create the first Time object
    Time time1(hour1, minute1, second1);

    // Input for the second time
    int hour2, minute2, second2;
    cin >> hour2 >> minute2 >> second2;

    // Create the second Time object
    Time time2(hour2, minute2, second2);

    // Add the two time objects
    Time result = time1.addTime(time2);

    // Output the result
    cout << "Time after add:" << result.hours << ":" << result.minutes << ":" << result.seconds << endl;

    return 0;
}
