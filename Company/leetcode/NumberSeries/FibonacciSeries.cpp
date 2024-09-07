#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
          int Fibonacci(int n)
          {
            if(n == 0)
            {
                return 0;
            }
            if (n == 1)
            {
                return 1;
            }
            int ans = Fibonacci(n-1) + Fibonacci(n-2);
            return ans;
          }
};
int main()
{
    int n;
    cin>>n;


    Solution solution;
    int result = solution.Fibonacci(n);
    cout<<result;

    return 0;
}