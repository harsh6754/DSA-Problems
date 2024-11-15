#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;  // Read the number of instructions

    vector<string> instructions(N);
    for (int i = 0; i < N; ++i) {
        cin >> instructions[i];  // Read each instruction
    }

    int minMoves = 0;
    string leftLeg = "down";  // Left leg starts at "down"
    string rightLeg = "up";   // Right leg starts at "up"

    // Process each instruction
    for (const string& instruction : instructions) {
        // If neither leg is on the required position, we need to move one leg
        if (leftLeg != instruction && rightLeg != instruction) {
            minMoves++;  // A move is required
            // Move the leg that is not on the required position
            if (leftLeg != instruction) {
                leftLeg = instruction;  // Move left leg to the required position
            } else {
                rightLeg = instruction;  // Move right leg to the required position
            }
        } 
        // If the left leg is not on the required position, move it
        else if (leftLeg != instruction) {
            leftLeg = instruction;  // Move the left leg to the required position
            minMoves++;
        }
        // If the right leg is not on the required position, move it
        else if (rightLeg != instruction) {
            rightLeg = instruction;  // Move the right leg to the required position
            minMoves++;
        }
    }

    cout << minMoves << endl;  // Output the minimum number of moves

    return 0;
}
