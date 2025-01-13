#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxArea(vector<int>& height){
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int max = 0;
        while(left<right){
            int area = min(height[left], height[right]) * (right - left);
            if(area>max){
                max = area;
            }
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return max;
    }
};
int main(){
    int n;
    cin>>n;

    vector<int> height(n);
    for(int i = 0;i<n;i++){
        cin>>height[i];
    }

    Solution solution;

    int result = solution.maxArea(height);
    cout<<result;

    return 0;
}