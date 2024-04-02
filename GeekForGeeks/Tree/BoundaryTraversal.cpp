#include<bits/stdc++.h>
using namespace std;

class node{
    public:
          int data;
          node* left;
          node* right;

          node(int d){
            this->data = d;
            this->left = NULL;
            this->right= NULL;
          }
};

node* buildTree(){
    cout<<"Enter Root node Value: ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    cout<<"Enter Left Children node Value of "<<data<<" : ";
    root->left = buildTree();

    cout<<"Enter Right Children node Value of "<<data<<" : ";
    root->right = buildTree();

    return root;
}

void printLevelOrder(node* root){
    if(root == NULL){
        return;
    }

    queue<node *>q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        cout << current->data << " ";

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);

        q.pop();
    }
}

void traverseLeft(node* root, vector<int>&ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left){
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

void traverseLeaf(node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root, vector<int>& ans){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }

    if(root->right){
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundary(node* root){
    vector<int>ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left,ans);

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);

    traverseRight(root->right,ans);

    return ans;


}

int main(){
    node* root = NULL;
    root = buildTree();

    cout<<"Printing Level Order Traversal: ";
    printLevelOrder(root);
    cout<<"\n";

    vector<int>result = boundary(root);
    cout<<"Boundary Traversal: ";
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}