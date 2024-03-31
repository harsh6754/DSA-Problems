//LRN -> Left Right Node

#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(){
   cout<<"Enter The Node Data Value : "<<endl;
   int data;
   cin>>data;

   if(data == -1){
        return NULL;
    }
 
   node *root = new node(data);

   cout<<"Enter the Left Children Node Value : "<< data<<endl;
   root->left= buildTree();

   cout<<"Enter the Right Children Node Value : "<< data<<endl;
   root->right = buildTree();

   return root;
}

void levelOrderTraversal(node* root){
    if(root == NULL){
        return;
    }

    queue<node *>q;
    q.push(root);

    while(!q.empty()){
        node *temp = q.front();
        cout<<temp->data<<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        q.pop();
    }
}

void postorder(node *root){
    if(root == NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root =NULL;
    root = buildTree();

    cout<<"Printing LevelOrderTraversal : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Postorder Traversal is : "<<endl;
    postorder(root);

    return 0;
}