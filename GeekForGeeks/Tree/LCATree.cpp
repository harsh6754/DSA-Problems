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
        this->right = NULL;
    }
};
node* buildTree(){
    cout<<"Enter Root Node Value "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    cout<<"Enter Left Child Node Value : "<<data<<endl;
    root->left = buildTree();

    cout<<"Enter Right Child Node Value : "<<data<<endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(node *root){
    if(root == NULL){
        return;
    }

    queue<node *>q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        q.pop();
        cout<<current->data<<" ";
        if(current->left){
            q.push(current->left);
        }
        if(current->right){
            q.push(current->right);
        }

    }
}

node* lca(node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) {
        return root;
    }
    node* left = lca(root->left, n1, n2);
    node* right = lca(root->right, n1, n2);
    if (!left) return right;
    if (!right) return left;
    return root;
}

int main(){
    node* root = NULL;
    root = buildTree();

    cout<<"Printing Level Order Traversal "<<endl;
    levelOrderTraversal(root);
    cout<<endl;


    int n1,n2;
    cout << "Enter two nodes to find their Lowest Common Ancestor: ";
    cin>>n1;
    cin>>n2;
    node* result = lca(root,n1,n2);
    if (result)
        cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: " << result->data << endl;
    else
        cout << "Lowest Common Ancestor doesn't exist!\n";

    return 0;
}