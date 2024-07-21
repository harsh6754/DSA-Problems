#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minChanges(int n, int k) {
        int x= n ^ k;
        int count = 0;
        while (x) {
            count += x & 1;
            x >>= 1; 
        }
        return count;
    }
};

int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    Solution solution;
    int result = solution.minChanges(n,k);
    cout<<result;

    return 0;
}