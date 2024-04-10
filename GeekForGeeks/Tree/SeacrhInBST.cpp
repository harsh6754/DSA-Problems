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
        root->right = insertIntoBST(root->right, d);
    }
    else if(d < root->data){
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

void takeInput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

bool search(Node* root, int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    if(root->data < target){
        return search(root->right, target);
    }
    else{
        return search(root->left, target);
    }
}

int main(){
    Node* root = NULL;
    cout << "Enter Data in BST" << endl;
    takeInput(root);

    int target;
    cout << "Enter target to search: ";
    cin >> target;

    if(search(root, target)){
        cout << "Present" << endl;
    }else{
        cout << "Not present" << endl;
    }

    return 0;
}
