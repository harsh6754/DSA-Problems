//LNR -> Left Node Right 

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node *right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node *buildTree(){
    cout<<"Enter the Root/Node Data : "<<endl;
    int data;
    cin>>data;

    if(data == -1)
        return NULL;
    
    node *root = new node(data);
    cout<<"Enter Left Children Node Value : "<<data<<endl;
    root->left = buildTree();
    cout<<"Enter Right Children Node Value : "<<data<<endl;
    root->right = buildTree();

    return root;
}
void levelOrderTraversal(node* root){
    if(root == NULL)
        return;
    
    queue<node *>q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        cout<< current->data << " ";

        if(current->left)
            q.push(current->left);
        if(current->right)
            q.push(current->right);
        q.pop();
        
    }
}

void inorder(node *root){
    if(root == NULL)
        return;
    
    inorder(root->left);
    cout<<root->data<< " ";
    inorder(root->right);
}

int main(){
    node* root = NULL;
    root = buildTree();

    cout<<"Printing Level Order Traversal : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;


    cout<<"Inorder Traversal is : "<<endl;
    inorder(root);

    return 0;
}