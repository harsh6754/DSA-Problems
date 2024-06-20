#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:

    bool canPlaceBalls(vector<int>&position,int minDistance,int m){
        int prevPosition = position[0];
        int count = 1;
        for(int i = 1;i<position.size();++i){
            int currentPosition = position[i];
            if(currentPosition - prevPosition >= minDistance){
                prevPosition = currentPosition;
                ++count;
            }
        }
        return count>=m;
    }
          int maxDistance(vector<int>&position,int m){
            int n = position.size();
            sort(position.begin(),position.end());
            int left = 1;
            int right = position.back();
            while(left<right){
                int mid = (left + right + 1)/2;
                if(canPlaceBalls(position,mid,m)){
                    left = mid;
                }else{
                    right = mid -1;
                }
            }
            return left;
          }
};
int main(){
    int n;
    cin>>n;

    vector<int>position(n);
    for(int i = 0;i<n;i++){
        cin>>position[i];
    }

    int m;
    cin>>m;

    Solution solution;
    int result = solution.maxDistance(position,m);
    cout<<result;

    return 0;
}