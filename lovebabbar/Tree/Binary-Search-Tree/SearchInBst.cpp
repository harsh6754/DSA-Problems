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

Node* insertIntoBST(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        root->right = insertIntoBST(root->right,d);
    }else{
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}

Node* takeInput(Node* root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }
    return root;
}

bool searchInBST(Node* root, int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    if(root->data > target){
        return searchInBST(root->left,target);
    } else {
        return searchInBST(root->right,target);
    }
}

int main(){
    Node* root = NULL;

    cout<<"Enter Data in BST (enter -1 to stop): ";
    root = takeInput(root);
    cout<<endl;

    int target;
    cout << "Enter target to search: ";
    cin>>target;
    bool result = searchInBST(root,target);
    if(result){
        cout << "Target found in BST\n";
    } else {
        cout << "Target not found in BST\n";
    }

    return 0;
}
