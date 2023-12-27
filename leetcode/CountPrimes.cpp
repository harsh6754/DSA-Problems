#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        std::vector<bool> prime(n + 1, true);

        prime[0] = prime[1] = false;
        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;

                for (int j = 2 * i; j < n; j = j + i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    int userInput;
    std::cout << "Enter a value for n: ";
    std::cin >> userInput;

    int result = solution.countPrimes(userInput);

    std::cout << "The number of prime numbers less than " << userInput << " is: " << result << std::endl;

    return 0;
}
