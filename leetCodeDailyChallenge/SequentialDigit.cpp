#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        
        for (int i = 1; i <= 9; ++i) {
            int num = i;
            
            for (int j = i + 1; j <= 9; ++j) {
                num = num * 10 + j;
                
                if (num >= low && num <= high) {
                    ans.push_back(num);
                }
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

int main() {
    int low, high;
    cin >> low >> high;
    
    if (low < 1 || high > 1000000000 || low > high) {
        cout << "Invalid input range\n";
        return 1;
    }

    vector<int> ans = Solution::sequentialDigits(low, high);

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
