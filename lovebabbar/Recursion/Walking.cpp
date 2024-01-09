#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
          int Walking(int src,int dest)
          {
            if(src == dest)
            {
                cout<<"Aah Gya Home"<<endl;
                return 1;
            }
            src+=1;
            return Walking(src,dest);
          }
};

int main()
{
    int src ;
   cin>>src;

    int dest;
    cin>>dest;


Solution solution;
int result = solution.Walking(src,dest);
cout<<result<<endl;



    return 0;
}