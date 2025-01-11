using namespace std;
class Solution{
    public:
    int findKthLargest(vector<int>& nums, int k){
        int size = nums.size();
        if(k>size){
            return -1;
        }
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i = 0;i<size;i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
         return pq.top();
    }
};