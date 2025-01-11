#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> findRepeatedAndMissing(const vector<int>& A) {
        int n = A.size();
        unordered_map<int, int> mp;
        int repeated = -1, missing = -1;

        for (int num : A) {
            mp[num]++;
        }

        for (int i = 1; i <= n; i++) {
            if (mp[i] == 2) {
                repeated = i;
            }
            if (mp[i] == 0) {
                missing = i;
            }
        }

        return {repeated, missing};
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i = 0;i<n;i++){
        cin>>A[i];
    }

    Solution solution;
    int result = solution.repeatedNumber(A);
    for(auto x : result){
        return x;
    }
    return 0;
}