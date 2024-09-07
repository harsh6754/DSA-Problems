#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
          int minMovesToSeat(vector<int>&seats,vector<int>&students){
            sort(seats.begin(),seats.end());
            sort(students.begin(),students.end());
            int ans = 0;
            for(int i = 0;i<seats.size();i++){
                ans+=abs(seats[i] - students[i]);
            }
            return ans;
          }
};
int main(){
    int n;
    cin>>n;

    vector<int>seats(n);
    for(int i = 0;i<n;i++){
        cin>>seats[i];
    }

    vector<int>students(n);
    for(int i = 0;i<n;i++){
        cin>>students[i];
    }

    Solution solution;
    int result = solution.minMovesToSeat(seats,students);
    cout<<result;

    return 0;

}