#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int current_person = 1;
        bool forward = true; // true means passing forward, false means passing backward

        while (time > 0) {
            if (forward) {
                current_person++;
                if (current_person == n + 1) {
                    current_person = n - 1;
                    forward = false;
                }
            } else {
                current_person--;
                if (current_person == 0) {
                    current_person = 2;
                    forward = true;
                }
            }
            time--;
        }

        return current_person;
    }
};

int main() {
    int n;
    cin >> n;

    int time;
    cin >> time;

    Solution solution;
    int result = solution.passThePillow(n, time);
    cout << result << endl;

    return 0;
}
