#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    
    int totalBalls, totalRuns, runsScored, ballsBowled;

    
    cin >> totalBalls >> totalRuns >> runsScored >> ballsBowled;

     
    int totalOvers = totalBalls / 6;
    int oversFinished = ballsBowled / 6 + (ballsBowled % 6) / 10;

   
    float currentRunRate = static_cast<float>(runsScored) / oversFinished;
    float totalRunRate = static_cast<float>(totalRuns) / totalOvers;

  
    string eligibility = (currentRunRate >= totalRunRate) ? "Eligible to Win" : "Not Eligible to Win";

    
    cout << totalOvers << endl;
    cout << oversFinished << '.' << (ballsBowled % 6) << endl;
    cout << fixed << setprecision(1) << currentRunRate << endl;
    cout << fixed << setprecision(1) << totalRunRate << endl;
    cout << eligibility << endl;

    return 0;
}
