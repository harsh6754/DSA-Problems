#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    pair<int, int> findRepeatedAndMissing(const vector<int>& A) {
        // int n = A.size();
        // unordered_map<int, int> mp;
        // int repeated = -1, missing = -1;

        // for (int num : A) {
        //     mp[num]++;
        // }

        // for (int i = 1; i <= n; i++) {
        //     if (mp[i] == 2) {
        //         repeated = i;
        //     }
        //     if (mp[i] == 0) {
        //         missing = i;
        //     }
        // }

        // return {repeated, missing};
        long long sum = 0, sum_of_squares = 0;
        long long expected_sum = 0, expected_sum_of_squares = 0;
        
        int n = A.size();
        
        for (int i = 1; i <= n; i++) {
            expected_sum += i;
            expected_sum_of_squares += (long long)i * i;
        }
        
        for (int num : A) {
            sum += num;
            sum_of_squares += (long long)num * num;
        }
        
        long long sum_diff = expected_sum - sum; // missing - repeated
        long long sum_of_squares_diff = expected_sum_of_squares - sum_of_squares; // missing^2 - repeated^2
        
        long long missing_plus_repeated = sum_of_squares_diff / sum_diff;
        
        int missing = (sum_diff + missing_plus_repeated) / 2;
        int repeated = missing - sum_diff;
        
        return {repeated, missing};
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    Solution solution;
    pair<int, int> result = solution.findRepeatedAndMissing(A);

    cout << "Repeated: " << result.first << ", Missing: " << result.second << endl;

    return 0;
}
