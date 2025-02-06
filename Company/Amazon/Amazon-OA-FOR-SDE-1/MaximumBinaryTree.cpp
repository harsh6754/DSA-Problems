#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

TreeNode* constructMaximumBinaryTree(vector<int>& nums,int start,int end){
    if(start>end){
        return NULL;
    }
    int maxIndex = start;
    for(int i = start+1;i<=end;i++){
        if(nums[i]>nums[maxIndex]){
            maxIndex = i;
        }
    }
    TreeNode* root = new TreeNode(nums[maxIndex]);
    root->left = constructMaximumBinaryTree(nums,start,maxIndex-1);
    root->right = constructMaximumBinaryTree(nums,maxIndex+1,end);
    return root;
}

void preOrder(TreeNode* root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }

    TreeNode* root = constructMaximumBinaryTree(nums,0,n-1);
    preOrder(root);
    cout<<endl;

    return 0;
}