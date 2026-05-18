#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool canReach(vector<int>& arr, int start){
        int n  = arr.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            if(arr[curr] == 0){
                return true;
            }

            int left = curr - arr[curr];
            int right = curr + arr[curr];

            if(left >= 0 && !visited[left]){
                visited[left] = true;
                q.push(left);
            }

            if(right < n && !visited[right]){
                visited[right] = true;
                q.push(right);
            }
        }
        return false;
    }
};
int main(){
    int n;
    cin>> n;
    vector<int>arr(n);
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int start;
    cin>> start;

    Solution solution;
    bool ans = solution.canReach(arr,0);
    cout<< ans << endl;
}