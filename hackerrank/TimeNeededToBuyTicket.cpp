#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int timeToBuyTickets(vector<int>& A, int k) {
        int step = 0;
        while (A[k] > 0) {
            for (int i = 0; i < A.size(); ++i) {
                if (A[i] > 0) {
                    A[i]--;
                    ++step;
                }
            }
        }
        return step;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int k;
    cin >> k;
    
    Solution solution;

    int result = solution.timeToBuyTickets(A, k);
    cout << result << endl;

    return 0;
}
