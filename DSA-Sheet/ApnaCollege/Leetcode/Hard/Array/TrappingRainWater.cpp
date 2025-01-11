#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int trap(vector<int>& height){
        int n = height.size();
        if(n == 0){
            return 0;
        }
        vector<int>left(n);
        vector<int>right(n);
        left[0] = height[0];
        right[n-1] = height[n-1];
        for(int i = 1;i<n;i++){
            left[i] = max(left[i-1],height[i]);
        }
        for(int i = n-2;i>=0;i--){
            right[i] = max(right[i+1],height[i]);
        }
        int water = 0;
        for(int i = 0;i<n;i++){
            water += min(left[i],right[i]) - height[i];
        }
        return water;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int>height(n);
    for(int i = 0;i<n;i++){
        cin>>height[i];
    }
    
    Solution solution;
    int result = solution.trap(height);
    cout<<result<<endl;
    
    return 0;
}