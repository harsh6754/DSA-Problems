#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(auto it: deck)
            mp[it]++;
        int ans = 0;
        for(auto it: mp)
            ans = __gcd(it.second, ans);
        if(ans<2)
            return false;
        return true;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> deck(n);
    for (int i = 0; i < n; i++)
    {
        cin >> deck[i];
    }

    Solution solution;
    bool result = solution.hasGroupsSizeX(deck);
    cout << (result ? "true" : "false");

    return 0;
}