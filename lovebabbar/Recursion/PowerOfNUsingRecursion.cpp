#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int power(int n)
        {
            if(n == 0)
                return 1;

            return 2*power(n-1);
        }
};

int main()
{
    int n ;
    cin>>n;

    Solution solution;
    int ans = solution.power(n);
    cout<<ans<<endl;

    return 0;

}