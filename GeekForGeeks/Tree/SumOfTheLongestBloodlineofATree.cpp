#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
          int data;
          Node* left;
          Node* right;

          Node(int d){
            this->data = d;
            this->left = NULL;
            this->right =NULL;
          }
};

Node* buildTree(){
    cout<<"Enter Root Node Value : "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node *root = new Node(data);
    cout<<"Enter Left Child Value : "<<data<<" ";
    root->left = buildTree();

    cout<<"Enter Right Child Tree : "<<data<<" ";
    root->right = buildTree();

    return root;
}

class Solution
{
public:
  void calc(Node * root,int cnt,int pathsum,int &ans,int &maxpath){
           if(root==NULL){
               return ;
           }
           cnt++;
           pathsum+=root->data;
           
           if(maxpath<cnt){
               maxpath=cnt;
               ans=pathsum;
           }else if(pathsum>ans && cnt==maxpath){
               ans=pathsum;
           }
           
          calc(root->left,cnt,pathsum,ans,maxpath);
          calc(root->right,cnt,pathsum,ans,maxpath);
           
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        if(root==NULL){
            return 0;
        }
        int ans=0;
        int maxpath=0;
        calc(root,0,0,ans,maxpath);
        return ans;
        
    }
};

int main(){
    Node* root = NULL;
    root = buildTree();

    Solution solution;
    int result = solution.sumOfLongRootToLeafPath(root);
    cout<<result;

    return 0;
}