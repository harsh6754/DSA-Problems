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
        root =  new Node(d);
        return root;
    }

   if(d > root->data){
        root->right = insertIntoBST(root->right, d);
    }
    else if(d < root->data){
        root->left = insertIntoBST(root->left, d);
    }
}

void takeInput(Node *root){
    int data;
    cin>>data;

    while(data == -1){
        root = insertIntoBST(root,data);
        cin>>data;
    }

}

int main(){
    Node* root = NULL;
    cout<<"Enter Data to Insert into BST "<<endl;
    takeInput(root);

    

    return 0;
}