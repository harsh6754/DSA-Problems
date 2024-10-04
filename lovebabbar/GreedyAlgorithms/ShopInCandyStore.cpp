#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> candyStore(vector<int>& candies, int n, int k){
        sort(candies.begin(), candies.end());
        int mini = 0;
        int buy = 0;
        int free = n - 1;

        // Calculate minimum cost
        while(buy <= free){
            mini += candies[buy];
            buy += 1;
            free -= k;
        }

        // Calculate maximum cost
        int maxi = 0;
        buy = n - 1;
        free = 0;
        while(free <= buy){
            maxi += candies[buy];
            buy -= 1;
            free += k;
        }

        // Store the results
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);

        return ans;
    }
};

int main(){
    int n;
    cin >> n;

    vector<int> candies(n);
    for(int i = 0; i < n; i++){
        cin >> candies[i];
    }

    int k;
    cin >> k;

    Solution solution;
    vector<int> result = solution.candyStore(candies, n, k);

    // Output the result
    cout << result[0] << " " << result[1] << endl;

    return 0;
}
