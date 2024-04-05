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
        this->right = NULL;
    }
};

Node *buildTree(){
    int data;
    cout<<"Enter Root Node Value : "<<endl;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);
    cout<<"Enter Left Child Node Value : "<<data <<" ";
    root->left = buildTree();

    cout<<"Enter Right Child Node Value : "<<data<<" ";
    root->right = buildTree();

    return root;
}

void solve(Node* root,int k,int node,vector<int> path,int& ans){
    if(root == NULL){
        return;
    }
    
    path.push_back(root->data);

    if(root->data == node && path.size()>k){
        int size = path.size();
        ans = path[size-1-k];
    }
    
    solve(root->left,k,node,path,ans);
    solve(root->right,k,node,path,ans);
    
    path.pop_back();
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    vector<int> path;
    int ans = 0;
    int count = -1;
    solve(root,k,node,path,ans);
    if(ans == 0){
        return -1;
    }
    return ans;
}

int main(){
    Node* root =NULL;
    root = buildTree();

    int k;
    cin>>k;

    int node;
    cin>>node;
    int result = kthAncestor(root,k,node);
    cout<<result;
    return 0;
}
