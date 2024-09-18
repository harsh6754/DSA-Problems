#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) {
        return add(a, b);
    }

private:
    int add(int a, int b) {
        if (a == 0 || b == 0) {
            return a | b;
        }
        return add(a ^ b, (a & b) << 1);
    }
};

int main(){
    int a;
    int b;
    cin>>a>>b;

    Solution solution;
    int result = solution.getSum(a,b);
    cout<<result;

    return 0;
}