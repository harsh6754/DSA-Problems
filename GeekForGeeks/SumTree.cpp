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

node* BuildTree(){
    int data;
    cout<<"Enter root Node Value :";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);
    cout<<"Enter Left Node Child Value : "<<data<<" : ";
    root->left = BuildTree();

    cout<<"Enter Right Node Child Value : "<<data<<" : ";
    root->right = BuildTree();

    return root;
}

bool isSumTree(node* root){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return true;
    }

    int left_sum = 0, right_sum = 0;

    if(root->left != NULL){
        left_sum = root->left->data;
        if(!isSumTree(root->left)){
            return false;
        }
    }

    if(root->right != NULL){
        right_sum = root->right->data;
        if(!isSumTree(root->right)){
            return false;
        }
    }

    return (root->data == left_sum + right_sum);
}

int main(){
    node* root = NULL;
    root = BuildTree();

    cout<<"Is Sum Tree? : ";
    if(isSumTree(root)){
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
