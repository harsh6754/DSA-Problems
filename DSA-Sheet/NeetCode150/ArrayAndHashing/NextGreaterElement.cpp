#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<int>nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        stack<int>st;
        unordered_map<int,int>nextGreater;
        for(int num : nums2){
            while(!st.empty() && st.top()<num){
                nextGreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        vector<int>ans;
        for(int num : nums1){
            if(nextGreater.find(num)!= nextGreater.end()){
                ans.push_back(nextGreater[num]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
int main(){
    int n1;
    cin>>n1;

    vector<int>nums1(n1);
    for(int i = 0;i<n1;i++){
        cin>>nums1[i];
    }

    int n2;
    cin>>n2;

    vector<int>nums2(n2);
    for(int i = 0;i<n2;i++){
        cin>>nums2[i];
    }

    Solution solution;
    vector<int>result = solution.nextGreaterElement(nums1,nums2);
    cout<<"[";
    for(int i = 0;i<n1;i++){
        cout<<result[i]<<" ";
    }
    cout<<"]";

    return 0;
}