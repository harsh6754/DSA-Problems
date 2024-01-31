#include <iostream>
#include <vector>
using namespace std;

// Function to determine the winner of the card game
string cardGameWinner(vector<int> piles) {
    // Check if the number of piles is less than 4
    if (piles.size() < 4) {
        return "Invalid";
    }

    // Check for negative values in the piles
    for (int pile : piles) {
        if (pile < 0) {
            return "Invalid";
        }
    }

    // Initialize variables to keep track of players' scores
    int ishitaScore = 0;
    int harshScore = 0;

    // Initialize pointers to keep track of the current ends of the piles
    int left = 0;
    int right = piles.size() - 1;

    // Flag to determine player's turn
    bool isIshitaTurn = true;

    while (left <= right) {
        if (isIshitaTurn) {
            // Ishita's turn, choose the maximum between left and right ends
            ishitaScore += max(piles[left], piles[right]);
            // Update the chosen end
            if (piles[left] > piles[right]) {
                left++;
            } else {
                right--;
            }
            isIshitaTurn = false;
        } else {
            // Harsh's turn, choose the maximum between left and right ends
            harshScore += max(piles[left], piles[right]);
            // Update the chosen end
            if (piles[left] > piles[right]) {
                left++;
            } else {
                right--;
            }
            isIshitaTurn = true;
        }
    }

    // Determine the winner
    if (harshScore == ishitaScore) {
        return "Both Harsh Agrawal and Ishita Goyal are declared winners";
    } else if (harshScore > ishitaScore) {
        return "Harsh Agrawal wins with " + to_string(harshScore) + " cards!";
    } else {
        return "Ishita Goyal wins with " + to_string(ishitaScore) + " cards!";
    }
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {5, 3, 4, 5},
        {-1, 5, 4, 5},
        {5, 4, 6},
        {7, 1, 4, 3}
    };

    // Run test cases
    for (auto& piles : testCases) {
        cout << "Input: ";
        for (int pile : piles) {
            cout << pile << " ";
        }
        cout << endl;
        cout << "Output: " << cardGameWinner(piles) << endl << endl;
    }

    return 0;
}
