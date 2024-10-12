#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the nth Fibonacci number
    int fibonacci(int n) {
        if(n == 0) return 0;  // Handle base case
        if(n == 1) return 1;  // Handle base case
        
        int prev1 = 1;
        int prev2 = 0;

        // Iterate to calculate the nth Fibonacci number
        for(int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    int n;
    cin >> n;

    Solution solution;
    // Print Fibonacci numbers from 0 to n-1
    for(int i = 0; i < n; i++) {
        int result = solution.fibonacci(i);
        cout << result << " ";
    }
    cout << endl;
    return 0;
}
