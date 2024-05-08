#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int getSum(int a, int b){
        while (b)
        {
            int carry =(a&b)<<1;
            a = a^b;
            b=carry;
        }
        return a;
        
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