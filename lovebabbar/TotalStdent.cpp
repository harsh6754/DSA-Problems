#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    const int totalStudents = 60;
    std::vector<bool> attendance(totalStudents, true);

    int absentStudents;

    std::cout << "Enter the number of absent students: ";
    std::cin >> absentStudents;

    // Mark absent students as false in the attendance vector
    for (int i = 0; i < absentStudents; ++i) {
        int studentIndex;
        std::cout << "Enter the index of absent student " << i + 1 << ": ";
        std::cin >> studentIndex;

        if (studentIndex >= 0 && studentIndex < totalStudents) {
            attendance[studentIndex] = false;
        } else {
            std::cout << "Invalid student index." << std::endl;
            --i;  // Retry input for invalid index
        }
    }

    // Calculate the number of present students using the count function
    int presentStudents = std::count(attendance.begin(), attendance.end(), true);
    std::cout << "Number of present students: " << presentStudents << std::endl;

    return 0;
}
