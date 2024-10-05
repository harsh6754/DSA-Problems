#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void minimumDays(int S, int N, int M){
        if(((N*6)<(M*7)&& S>6) || M>N){
            cout<<"No";
        }else{
            int days = (M*S)/N;
            if(((M*S)%N)!=0){
                days++;
            }
         cout<<"Yes "<<days<<endl;
        }
    }
};
int main(){
    int S,N,M;
    // N- Maximum unit of food you can buy each day.
    // S- Number of days you are required to survive.
    // M- Unit of food required each day to survive.
    cin>>S>>N>>M;

    Solution solution;
    solution.minimumDays(S,N,M);

    return 0;
}