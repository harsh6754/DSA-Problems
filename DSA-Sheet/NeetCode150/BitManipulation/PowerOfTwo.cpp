#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        while (n % 2 == 0) {
            n /= 2;
        }
        return n == 1;
    }
};
int main(){
    int n;
    cin>>n;

    Solution solution;
    bool result = solution.isPowerOfTwo(n);
    cout<<result ? 1 : 0;

    return 0;
}