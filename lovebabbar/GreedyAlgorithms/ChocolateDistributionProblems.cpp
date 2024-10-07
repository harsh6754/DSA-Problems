#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int MinChocoDistribution(int N, int M , vector<int>& A){
        sort(A.begin(),A.end());
        int i = 0;
        int j = M-1;
        int mini = INT_MAX;
        while(j < A.size()){
            int diff = A[j]-A[i];
            mini = min(mini,diff);
            i+=1;
            j+=1;
        }
        return mini;
    }
};
int main(){
    int N;
    cin>>N;

    int M;
    cin>>M;

    vector<int>A(N);
    for(int i = 0;i<N;i++){
        cin>>A[i];
    }

    Solution solution;
    int result = solution.MinChocoDistribution(N,M,A);
    cout<<result;

    return 0;
}