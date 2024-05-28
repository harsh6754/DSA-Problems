#include <iostream>
using namespace std;
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0) return true;
        if (num % 10 == 0) return false;
        return true;
    }
};

int main() {
    Solution solution;
    int num;
    cin >> num;

    bool result = solution.isSameAfterReversals(num);

    if (result) {
        return 0;  
    } else {
        return 1;  
    }
}
