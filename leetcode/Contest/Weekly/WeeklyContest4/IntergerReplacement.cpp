#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        long long num = n; // convert to long long to avoid overflow
        int count = 0;
        while (num > 1) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                if (num == 3 || (num & 2) == 0) {
                    num -= 1;
                } else {
                    num += 1;
                }
            }
            count++;
        }
        return count;
    }
};


int main(){
    int n;
    cin>>n;

    Solution solution;
    int result = solution.integerReplacement(n);
    cout<<result<<endl;

    return 0;
}