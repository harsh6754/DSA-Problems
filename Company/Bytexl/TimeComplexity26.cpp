#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void TimeComplexity(int n)
    {
      if(n%2 != 0)
      {
        cout<<"A section"<<endl;
        
      }
      else{
        cout<< "B section"<<endl;
      }
    }
};
int main()
{
  int n;
  cin>>n;
  
  Solution solution;
  solution.TimeComplexity(n);
  return 0;
}
