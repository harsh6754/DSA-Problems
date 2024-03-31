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
    int data;
    cout<<"Enter Root Node Value :";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    cout<<"Enter Left Children Node Value : "<<data<<endl;
    root->left = buildTree();

    cout<<"Enter Right Children Node Value : "<<data<<endl;
    root->right = buildTree();

    return root;
}

int height(node* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}

bool isBalanced(node* root) {
    if (root == NULL) return true;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;

    return false;
}

int main(){
    node *root = NULL;
    root = buildTree();

    if(isBalanced(root))
        cout << "Tree is balanced." << endl;
    else
        cout << "Tree is not balanced." << endl;

    return 0;
}
